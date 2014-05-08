#import <JFFUtils/Blocks/JFFUtilsBlockDefinitions.h>
#import <JFFUtils/Blocks/JUContainersHelperBlocks.h>


#import <Foundation/Foundation.h>


/**
 This category adds extensions that allow using the functional programming patterns in your applications. 
 The methods are built on top of the -[NSArray enumerateObjectsUsingBlock:] method and are capable of solving the task of
 
 * iterating
 * filtering array contents
 * transforming the array ( mapping )
 
 
 */
@interface NSArray (BlocksAdditions)

#pragma mark -
#pragma mark BlocksAdditions


/**
   Creates a new NSArray of length N containing the values returned by the block.
 
   @param N  Size of the new array
   @param block A block that builds new objects to fill array with. 
   Note : The producer block cannot return nil. In this case the function will crash.
 
   @return A new NSArray instance
 */
+ (instancetype)arrayWithSize:(NSUInteger)N
                     producer:(JFFProducerBlock)block;



/**
   Creates a new NSArray of length [0..N] containing the values returned by the block.
 
   @param N  The maximal size of the new array
   @param block A block that builds new objects to fill array with
   Note : The producer block may return nil. It sill be ignored and the size of the array will be smaller than N.

   @return A new NSArray instance
   Note : the array does not contain NSNull gaps.
 */
+ (instancetype)arrayWithCapacity:(NSUInteger)N
             ignoringNilsProducer:(JFFProducerBlock)block;



/**
Calls block once for each element in self, passing that element as a parameter.
 
 @param block Performs some action with the given object. It is executed for each element of the array. The execution order is not guaranteed to be the same as the order of elements in the array.
 */
- (void)each:(JFFActionBlock)block;



/**
Invokes block once for each element of self.
Creates a new NSArray containing the values returned by the block.
 
 @param block - a block that perfroms the transform of element in this array to element in the new array.
 Note : the mapping block should not return nil. Otherwise the function will crash.
 
 @return a new NSArray of mapped objects
 
 */
- (instancetype)map:(JFFMappingBlock)block;




/** Invokes block once for each element of self. Creates a new NSArray
containing the values returned by the block. If the block returns nil
its value is ignored and not pushed to the target aray.
 
 @param block - a block that perfroms the transform of element in this array to element in the new array.
 Note : the mapping block may return nil.

 @return A new NSArray of mapped objects. 
 Note : the array does not contain NSNull gaps.
 */
- (instancetype)forceMap:(JFFMappingBlock)block;


/**
Invokes block once for each element of self.
Creates a new NSArray containing the values returned by the block.
 
 @param block A block that perfroms the transform of element in this array to element in the new array.
 Note : in case the mapping block returns nil the entire result is nil.
 
 @param outError A pointer to the NSError out parameter object. 

 @return a new NSArray of mapped objects. If an error occurs, the result of the entire function is nil.
 */
- (instancetype)map:(JFFMappingWithErrorBlock)block
              error:(NSError *__autoreleasing *)outError;


/**
Invokes block once for each element of self.
Creates a new NSArray containing the values returned by the block.
 
 @param block A block that perfroms the transform of element in this
array to element in the new array.  Note : in case the mapping block
returns nil the result will contain less records.
 
 @param outError A pointer to the NSError out parameter object. 

 @return a new NSArray of mapped objects. 
 If an error occurs, the result of the entire function is nil.
 */
-(instancetype)mapIgnoringNilError:( JFFMappingWithErrorBlock )bloc
                             error:( NSError** )outError;



/** Same as [NSArray map:error:]. The mapping block takes the element
index into account.

 Note : in case the mapping block returns nil the entire result is nil.
 
 @param outError A pointer to the NSError out parameter object. 

 @return a new NSArray of mapped objects. If an error occurs, the result of the entire function is nil.
*/
(instancetype)mapWithIndex:(JFFMappingWithErrorAndIndexBlock)block
                     error:(out NSError *__autoreleasing *)outError;


//Invokes block once for each element of self.
//Creates a new NSDictionary containing the values and keys returned by the block.
- (NSDictionary *)mapDict:(JFFMappingDictBlock)block;



/**
Invokes the block passing in successive elements from self.
Creates a new NSArray containing those elements for which the block returns a YES value.
 
 @param predicate - a predicate. It takes an object and returns YES if the object matches a certain condition.
 
 @return - a new NSArray of objects that fit predicate requirements
 */
- (instancetype)select:(JFFPredicateBlock)predicate;


/**
Same as [NSArray select:] but the predicate block takes the element index into account.
 
 @param predicate A predicate. It takes an object and returns YES if the object matches a certain condition.
 
 @return A new NSArray of objects that fit predicate requirements
 */
- (instancetype)selectWithIndex:(JFFPredicateWithIndexBlock)predicate;



/**
 Invokes the block passing in successive elements from self.
 Creates a new NSArray containing all elements of all arrays returned the block.
 
 @param block A block for retrieving an NSArray from the array element. All its elements will be appenden to the result array.
 
 @return A flat array.
 
 
 For example,
 
```
 NSArray* tree = @[ @[ @1, @2 ], @[ @3, @4 ]  ] ];
 NSArray result = [ tree flatten: ^NSArray*( id element )
 {
    return element;
 } ];
 // returns @[ @1, @2, @3, @4 ]
```

 */
- (instancetype)flatten:(JFFFlattenBlock)block;



/**
Invokes the block passing in successive elements from self, returning a count of those elements for which the block returns a YES value.
 
 @param predicate A predicate that takes an object and returns YES if the object matches a certain condition.
 
 @return number of objects matching the predicate
 */
- (NSUInteger)count:(JFFPredicateBlock)predicate;


/**
 Invokes the block passing in successive elements from self, returning the first element for which the block returns a YES value.
 
 @param predicate A predicate that takes an object and returns YES if the object matches a certain condition.
 
 @return - the first object matching the predicate
 Note : If none of the objects matches the predicate nil is returned.
 */
 - (id)firstMatch:(JFFPredicateBlock)predicate;


/**
 Invokes the block passing in elements from self in the reverse order.
 The function returns the last element for which the block returns a YES value.
 
 @param predicate A predicate that takes an object and returns YES if the object matches a certain condition.
 
 @return The last object matching the predicate. 
 Note : If none of the objects matches the predicate nil is returned.
*/ 
 - (id)lastMatch:(JFFPredicateBlock)predicate;



/**
 Invokes the block passing in successive elements from self, returning an index of the first element for which the block returns a YES value.
 
 @param predicate A predicate that takes an object and returns YES if the object matches a certain condition.
 
 @return index of the found object or NSNotFound otherwise
 */
- (NSUInteger)firstIndexOfObjectMatch:(JFFPredicateBlock)predicate;




/**
 Iterates two arrays simultaneously. Objects with same indices are passed to the block.
 
 @param other An array of the same size
 @param block Performs some action with the given pair of objects. Both objects have the same index in the corresponding arrays ( "self" and "other" ).
 */
- (void)transformWithArray:(NSArray *)other
                 withBlock:(JFFTransformBlock)block;


/**
Splits the array to N shards. The distribution is defined by the **elementIndexBlock**.

@param N Number of shards to split the array into.
@param block A block that defines which element goes to which shard.

@return Array of NSAray shards
*/
- (instancetype)devideIntoArrayWithSize:(NSUInteger)N
                      elementIndexBlock:(JFFElementIndexBlock)block;


/**
 Same as [NSArray firstMatch:]
 
 @param predicate A predicate that takes an object and returns YES if the object matches a certain condition.
 
 @return - the first object matching the predicate
 Note : If none of the objects matches the predicate nil is returned.
 */
- (BOOL)any:(JFFPredicateBlock)predicate;


/**
Same as [NSArray select:]

@param predicate - a predicate. It takes an object and returns YES if the object matches a certain condition.
 
 @return - a new NSArray of objects that fit predicate requirements
*/
- (BOOL)all:(JFFPredicateBlock)predicate;

@end
