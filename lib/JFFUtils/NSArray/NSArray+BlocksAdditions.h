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
 
   @param N  - size of the new array
   @param block - a block that builds new objects to fill array with
 
   @return - a new NSArray instance
 */
+ (instancetype)arrayWithSize:(NSUInteger)size
                     producer:(JFFProducerBlock)block;

//Calls block once for number from 0(zero) to (size_ - 1)
//Creates a new NSArray containing the values returned by the block.
+ (instancetype)arrayWithCapacity:(NSUInteger)size
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
 
 @return a new NSArray of mapped objects
 
 */
- (instancetype)map:(JFFMappingBlock)block;


//Invokes block once for each element of self.
//Creates a new NSArray containing the values returned by the block.
//if error happens it is suppressed
- (instancetype)forceMap:(JFFMappingBlock)block;

//Invokes block once for each element of self.
//Creates a new NSArray containing the values returned by the block.
//or return nil if error happens
- (instancetype)map:(JFFMappingWithErrorBlock)block
              error:(NSError *__autoreleasing *)outError;

-(instancetype)mapIgnoringNilError:( JFFMappingWithErrorBlock )block error:( NSError** )outError;



//Invokes block once for each element of self.
//Creates a new NSArray containing the values returned by the block. Passes index of element in block as argument.
//or return nil if error happens
- (instancetype)mapWithIndex:(JFFMappingWithErrorAndIndexBlock)block
                       error:(NSError *__autoreleasing *)outError;

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
 *//**
 Invokes the block passing in successive elements from self, returning the first element for which the block returns a YES value.
 
 @param predicate A predicate that takes an object and returns YES if the object matches a certain condition.
 
 @return - the first object matching the predicate
 */
 - (id)firstMatch:(JFFPredicateBlock)predicate;

//Invokes the block passing in successive elements from self,
//returning the last element for which the block returns a YES value
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



//Invokes the block passing parallel in successive elements from self and other NSArray,
- (instancetype)devideIntoArrayWithSize:(NSUInteger)size
                      elementIndexBlock:(JFFElementIndexBlock)block;

- (BOOL)any:(JFFPredicateBlock)predicate;

- (BOOL)all:(JFFPredicateBlock)predicate;

@end
