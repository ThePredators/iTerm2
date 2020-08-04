//
//  iTermEncoderGraphRecord.h
//  iTerm2SharedARC
//
//  Created by George Nachman on 7/28/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface iTermEncoderGraphRecord: NSObject
@property (nonatomic, readonly) NSDictionary<NSString *, id> *pod;
@property (nonatomic, readonly) NSArray<iTermEncoderGraphRecord *> *graphRecords;
@property (nonatomic, readonly) NSInteger generation;
@property (nonatomic, readonly) NSString *identifier;
@property (nonatomic, readonly) NSString *key;
@property (nonatomic, readonly, weak) iTermEncoderGraphRecord *parent;
@property (nonatomic, readonly) id propertyListValue;
@property (nonatomic, strong) NSNumber *rowid;
@property (nonatomic, readonly) NSData *data;  // encoded pod

+ (instancetype)withPODs:(NSDictionary<NSString *, id> *)pod
                  graphs:(NSArray<iTermEncoderGraphRecord *> *)graphRecords
              generation:(NSInteger)generation
                     key:(NSString *)key
              identifier:(NSString *)identifier
                   rowid:(NSNumber *_Nullable)rowid;

- (NSComparisonResult)compareGraphRecord:(iTermEncoderGraphRecord *)other;

// You probably want to use arrayWithKey or dictionaryWithKey. This is very low level.
- (iTermEncoderGraphRecord * _Nullable)childRecordWithKey:(NSString *)key
                                               identifier:(NSString *)identifier;

- (void)enumerateArrayWithKey:(NSString *)key
                        block:(void (^NS_NOESCAPE)(NSString *identifier,
                                                   NSInteger index,
                                                   iTermEncoderGraphRecord *obj,
                                                   BOOL *stop))block;
- (NSArray<iTermEncoderGraphRecord *> * _Nullable)recordArrayWithKey:(NSString *)key;
- (NSArray *)arrayWithKey:(NSString *)key;
- (NSInteger)integerWithKey:(NSString *)key error:(out NSError **)error;
- (NSString *)stringWithKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END