# product_type
generic product type (tuple like) optimized for simplicity and small debug builds

## what is a product type?
The names comes from the possible states an agrigate of variables can be in. if I have an aggrigate type of a char or a bool then I can be in 256 different states for the char and 2 more for the bool meaning that all the possible combination of states I can be in is the product of 256 and 2. Analogous to this is a sum type like a std::variant where the possible states are the sum of the states of all types which the variant can hold. In other words its a fancy name for types like tuple and pair.

## why another library, isnt std::tuple good enough?
std::tuple is the right choice for most applications but it has some drawbacks. In the embedded field it is often not just important what the size and efficientcy of a release build is, its also important how big and efficient a debug build is (it still has to fit on the chip and meet timing deadlines). Here std::tuple can really cause problems. Also if you are like me and love to go crazy with DSLs and metaprogramming a std::tuple will slow down compile times to the extent that it can limit ones modeling power.

## what can I do with this product_type?
the familiar ```get<0>(t)``` syntax works on product_type as well as aggrigate initialization using CTAD. interestingly the actual underlying type (or at least its template parameters and layout) of the product type is implementation defined, this gives us room to potentially optimize. Normally one should use CTAD to make a product type (do not specify the parameters) or use the alias ```make_product_type<Ts...>```. 
I hope to support ```tie()``` in a future version, its entirely possible within the paradigm. 


