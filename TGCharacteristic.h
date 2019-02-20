//
//  TGCharacteristic.h
//  TOGOBlutoothDemo
//
//  Created by ShuHuan on 2017/4/6.
//  Copyright © 2017年 shuhuan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "TGBluetoothBlocks.h"
#import "TGPeripheral.h"

@class TGPeripheral;
@class TGService;
@class TGDescriptor;
@interface TGCharacteristic : NSObject
/*!
 * @property UUID
 *
 * @discussion
 *      The Bluetooth UUID of the characteristic.
 *
 */
@property(readonly, nonatomic, nullable) CBUUID *UUID;

/*!
 * @property service
 *
 *  @discussion
 *      A back-pointer to the service this characteristic belongs to.
 *
 */
@property(assign, readonly, nonatomic, nullable) TGService *service;

/*!
 * @property properties
 *
 *  @discussion
 *      The properties of the characteristic.
 *
 */
@property(readonly, nonatomic) CBCharacteristicProperties properties;

/*!
 * @property value
 *
 *  @discussion
 *      The value of the characteristic.
 *
 */
@property(retain, readonly, nullable) NSData *value;

/*!
 * @property descriptors
 *
 *  @discussion
 *      A list of the CBDescriptors that have so far been discovered in this characteristic.
 *
 */
@property(retain, readonly, nullable) NSArray<TGDescriptor *> *descriptors;

/*!
 * @property isBroadcasted
 *
 *  @discussion
 *      Whether the characteristic is currently broadcasted or not.
 *
 */
@property(readonly) BOOL isBroadcasted NS_DEPRECATED(NA, NA, 5_0, 8_0);

/*!
 * @property isNotifying
 *
 *  @discussion
 *      Whether the characteristic is currently notifying or not.
 *
 */
@property(readonly) BOOL isNotifying;

/*!
 * @property ownPeripheral
 *
 * @discussion
 *      the peripheral that this characteristic belong to
 *
 */
@property (nonatomic, weak, readonly, nullable) TGPeripheral *ownPeripheral;

- (nullable instancetype)init NS_UNAVAILABLE;
- (nullable instancetype)initWithCharacteristic:(nullable CBCharacteristic *)characteristic
                               andOwnPeripheral:(nullable TGPeripheral *)peripheral;

/*!
 *  @method readValueWithBlock:
 *
 *  @param block            callback with this block,(MPPeripheral *peripheral,MPharacteristic *characteristic,NSError *error)
 *
 *  @discussion				Reads the characteristic value for <i>self</i>.
 *
 *  @see					MPPeripheralReadValueForCharacteristicBlock
 */
- (void)readValueWithBlock:(nullable TGPeripheralReadValueForCharacteristicBlock)block;

/*!
 *  @method writeValue:type:withBlock:
 *
 *  @param data				The value to write.
 *  @param type				The type of write to be executed.
 *  @param block            callback with this block;
 *
 *  @discussion				Writes <i>value</i> to <i>self</i>'s characteristic value.
 *							If the <code>CBCharacteristicWriteWithResponse</code> type is specified, {@link MPPeripheralWriteValueForCharacteristicsBlock}
 *							is called with the result of the write request.
 *							If the <code>CBCharacteristicWriteWithoutResponse</code> type is specified, the delivery of the data is best-effort and not
 *							guaranteed.
 *
 *	@see					CBCharacteristicWriteType
 *  @seealso                MPPeripheralWriteValueForCharacteristicsBlock
 */
- (void)writeValue:(nullable NSData *)data
              type:(CBCharacteristicWriteType)type
         withBlock:(nullable TGPeripheralWriteValueForCharacteristicsBlock)block
     withTypeBlock:(TGBleInstructType)instructType;

/*!
 *  @method setNotifyValue:withBlock:
 *
 *  @param enabled			Whether or not notifications/indications should be enabled.
 *  @param block            callback with this block
 *
 *  @discussion				Enables or disables notifications/indications for the characteristic value of <i>characteristic</i>. If <i>characteristic</i>
 *							allows both, notifications will be used.
 *                          When notifications/indications are enabled, updates to the characteristic value will be received via block.
 *                          Since it is the peripheral that chooses when to send an update,
 *                          the application should be prepared to handle them as long as notifications/indications remain enabled.
 *
 *  @see					MPPeripheralNotifyValueForCharacteristicsBlock
 */
- (void)setNotifyValue:(BOOL)enabled
             withBlock:(nullable TGPeripheralNotifyValueForCharacteristicsBlock)block;

/*!
 *  @method discoverDescriptorsFWithBlcok:
 *
 *  @param block            callback with this block;
 *
 *  @discussion				Discovers the characteristic descriptor(s) of <i>self</i>.
 *
 *  @see                    MPPeripheralDiscoverDescriptorsForCharacteristicBlock
 */
- (void)discoverDescriptorsWithBlock:(nullable TGPeripheralDiscoverDescriptorsForCharacteristicBlock)block;
@end
