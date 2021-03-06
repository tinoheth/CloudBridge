//
//  CBREntityDescription.m
//  Pods
//
//  Created by Oliver Letterer.
//  Copyright 2015 __MyCompanyName__. All rights reserved.
//

#import "CBREntityDescription.h"
#import "CBRDatabaseAdapter.h"

static NSDictionary *indexBy(NSArray *array, NSString *key)
{
    NSMutableDictionary *result = [NSMutableDictionary dictionary];

    for (id object in array) {
        result[[object valueForKey:key]] = object;
    }

    return result;
}



@implementation CBRAttributeDescription

- (instancetype)initWithDatabaseAdapter:(id<CBRDatabaseAdapter>)databaseAdapter
{
    if (self = [super init]) {
        _databaseAdapter = databaseAdapter;
    }
    return self;
}

@end



@implementation CBRRelationshipDescription

- (CBREntityDescription *)destinationEntity
{
    return [self.databaseAdapter entityDescriptionForClass:NSClassFromString(self.destinationEntityName)];
}

- (instancetype)initWithDatabaseAdapter:(id<CBRDatabaseAdapter>)databaseAdapter
{
    if (self = [super init]) {
        _databaseAdapter = databaseAdapter;
    }
    return self;
}

@end



@implementation CBREntityDescription

- (NSDictionary *)attributesByName
{
    return indexBy(self.attributes, @"name");
}

- (NSDictionary *)relationshipsByName
{
    return indexBy(self.relationships, @"name");
}

- (NSArray *)subentities
{
    NSMutableArray *result = [NSMutableArray array];

    for (NSString *name in self.subentityNames) {
        [result addObject:[self.databaseAdapter entityDescriptionForClass:NSClassFromString(name)]];
    }

    return result;
}

- (instancetype)initWithDatabaseAdapter:(id<CBRDatabaseAdapter>)databaseAdapter
{
    if (self = [super init]) {
        _databaseAdapter = databaseAdapter;
    }
    return self;
}

@end
