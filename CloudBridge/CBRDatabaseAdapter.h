/**
 CloudBridge
 Copyright (c) 2015 Oliver Letterer <oliver.letterer@gmail.com>, Sparrow-Labs

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

#import <Foundation/Foundation.h>

@class CBREntityDescription;
@protocol CBRPersistentObject;



/**
 @abstract  <#abstract comment#>
 */
@protocol CBRDatabaseAdapter <NSObject>

@required
@property (nonatomic, readonly) NSArray /* <CBREntityDescription> */ *entities;

@required
- (CBREntityDescription *)entityDescriptionForClass:(Class)persistentClass;

@optional
- (void)saveChangesForPersistentObject:(id<CBRPersistentObject>)persistentObject;

@required
- (id<CBRPersistentObject>)newMutablePersistentObjectOfType:(CBREntityDescription *)entityDescription;

@required
- (id<CBRPersistentObject>)persistentObjectOfType:(CBREntityDescription *)entityDescription withPrimaryKey:(id)primaryKey;

@required
- (NSDictionary *)indexedObjectsOfType:(CBREntityDescription *)entityDescription withValues:(NSSet *)values forAttribute:(NSString *)attribute;

@required
- (NSArray *)fetchObjectsOfType:(CBREntityDescription *)entityDescription withPredicate:(NSPredicate *)predicate;

@required
- (void)mutatePersistentObject:(id<CBRPersistentObject>)persitentObject
                     withBlock:(void(^)(id<CBRPersistentObject> persistentObject))mutation
                    completion:(void(^)(id<CBRPersistentObject> persistentObject))completion;

@required
- (void)mutatePersistentObjects:(NSArray *)persitentObject
                     withBlock:(NSArray *(^)(NSArray *persistentObjects))mutation
                    completion:(void(^)(NSArray *persistentObjects))completion;

@required
- (void)deletePersistentObjects:(NSArray *)persistentObjects;

@end
