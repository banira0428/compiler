      
        
     
       
                  
        
              
              
                
                    
        
                
           
           
    


 
  
   
   
   
   
   
   
   
   
   
   
    
    .text
main:
|-type : PROGRAM, 
  |-type : DECLARATIONS, 
    |-type : FUNC_DEFINE, 
      |-type : FUNC, 
        |-type : IDENT, variable : quicksort
        |-type : PARAMS, 
          |-type : PARAM, 
            |-type : IDENT, variable : a
          |-type : PARAMS, 
            |-type : PARAM, 
              |-type : IDENT, variable : l
            |-type : PARAM, 
              |-type : IDENT, variable : r
        |-type : DECLARATIONS, 
          |-type : DEFINE, 
            |-type : DECL_IDENTS, 
              |-type : IDENT, variable : v
              |-type : DECL_IDENTS, 
                |-type : IDENT, variable : i
                |-type : DECL_IDENTS, 
                  |-type : IDENT, variable : j
                  |-type : DECL_IDENTS, 
                    |-type : IDENT, variable : t
          |-type : DECLARATIONS, 
            |-type : DEFINE, 
              |-type : DECL_IDENTS, 
                |-type : IDENT, variable : ii
        |-type : STATEMENTS, 
          |-type : STATEMENT, 
            |-type : IF, 
              |-type : IF_B, 
                |-type : GT, 
                  |-type : IDENT, variable : r
                  |-type : IDENT, variable : l
                |-type : STATEMENTS, 
                  |-type : STATEMENT, 
                    |-type : ASSIGN, 
                      |-type : IDENT, variable : v
                      |-type : ARRAY, 
                        |-type : ARRAY_INDEX, 
                          |-type : IDENT, variable : r
                  |-type : STATEMENTS, 
                    |-type : STATEMENT, 
                      |-type : ASSIGN, 
                        |-type : IDENT, variable : i
                        |-type : MINUS, 
                          |-type : IDENT, variable : l
                          |-type : NUM, value : 1, 
                    |-type : STATEMENTS, 
                      |-type : STATEMENT, 
                        |-type : ASSIGN, 
                          |-type : IDENT, variable : j
                          |-type : IDENT, variable : r
                      |-type : STATEMENTS, 
                        |-type : STATEMENT, 
                          |-type : FOR, 
                            |-type : FOR_ASIGN, 
                            |-type : FOR_COND, 
                            |-type : FOR_EXPR, 
                            |-type : STATEMENTS, 
                              |-type : STATEMENT, 
                                |-type : WHILE, 
                                  |-type : LT, 
                                    |-type : ARRAY, 
                                      |-type : ARRAY_INDEX, 
                                        |-type : INC, 
                                          |-type : IDENT, variable : i
                                    |-type : IDENT, variable : v
                              |-type : STATEMENTS, 
                                |-type : STATEMENT, 
                                  |-type : WHILE, 
                                    |-type : GT, 
                                      |-type : ARRAY, 
                                        |-type : ARRAY_INDEX, 
                                          |-type : DEC, 
                                            |-type : IDENT, variable : j
                                      |-type : IDENT, variable : v
                                |-type : STATEMENTS, 
                                  |-type : STATEMENT, 
                                    |-type : IF, 
                                      |-type : GTE, 
                                        |-type : IDENT, variable : i
                                        |-type : IDENT, variable : j
                                      |-type : STATEMENT, 
                                        |-type : BREAK, 
                                  |-type : STATEMENTS, 
                                    |-type : STATEMENT, 
                                      |-type : ASSIGN, 
                                        |-type : IDENT, variable : t
                                        |-type : ARRAY, 
                                          |-type : ARRAY_INDEX, 
                                            |-type : IDENT, variable : i
                                    |-type : STATEMENTS, 
                                      |-type : STATEMENT, 
                                        |-type : ASSIGN, 
                                          |-type : ARRAY, 
                                            |-type : ARRAY_INDEX, 
                                              |-type : IDENT, variable : i
                                          |-type : ARRAY, 
                                            |-type : ARRAY_INDEX, 
                                              |-type : IDENT, variable : j
                                      |-type : STATEMENTS, 
                                        |-type : STATEMENT, 
                                          |-type : ASSIGN, 
                                            |-type : ARRAY, 
                                              |-type : ARRAY_INDEX, 
                                                |-type : IDENT, variable : j
                                            |-type : IDENT, variable : t
                        |-type : STATEMENTS, 
                          |-type : STATEMENT, 
                            |-type : ASSIGN, 
                              |-type : IDENT, variable : t
                              |-type : ARRAY, 
                                |-type : ARRAY_INDEX, 
                                  |-type : IDENT, variable : i
                          |-type : STATEMENTS, 
                            |-type : STATEMENT, 
                              |-type : ASSIGN, 
                                |-type : ARRAY, 
                                  |-type : ARRAY_INDEX, 
                                    |-type : IDENT, variable : i
                                |-type : ARRAY, 
                                  |-type : ARRAY_INDEX, 
                                    |-type : IDENT, variable : r
                            |-type : STATEMENTS, 
                              |-type : STATEMENT, 
                                |-type : ASSIGN, 
                                  |-type : ARRAY, 
                                    |-type : ARRAY_INDEX, 
                                      |-type : IDENT, variable : r
                                  |-type : IDENT, variable : t
                              |-type : STATEMENTS, 
                                |-type : STATEMENT, 
                                  |-type : FUNCCALL, 
                                    |-type : IDENT, variable : quicksort
                                    |-type : ARGS, 
                                      |-type : IDENT, variable : a
                                      |-type : ARGS, 
                                        |-type : IDENT, variable : l
                                        |-type : ARGS, 
                                          |-type : MINUS, 
                                            |-type : IDENT, variable : i
                                            |-type : NUM, value : 1, 
                                |-type : STATEMENTS, 
                                  |-type : STATEMENT, 
                                    |-type : FUNCCALL, 
                                      |-type : IDENT, variable : quicksort
                                      |-type : ARGS, 
                                        |-type : IDENT, variable : a
                                        |-type : ARGS, 
                                          |-type : PLUS, 
                                            |-type : IDENT, variable : i
                                            |-type : NUM, value : 1, 
                                          |-type : ARGS, 
                                            |-type : IDENT, variable : r
    |-type : DECLARATIONS, 
      |-type : FUNC_DEFINE, 
        |-type : FUNC, 
          |-type : IDENT, variable : main
          |-type : PARAMS, 
          |-type : DECLARATIONS, 
            |-type : ARRAY_DEFINE, 
              |-type : ARRAY, 
          |-type : STATEMENTS, 
            |-type : STATEMENT, 
              |-type : ASSIGN, 
                |-type : ARRAY, 
                  |-type : ARRAY_INDEX, 
                    |-type : NUM, value : 0, 
                |-type : NUM, value : 10, 
            |-type : STATEMENTS, 
              |-type : STATEMENT, 
                |-type : ASSIGN, 
                  |-type : ARRAY, 
                    |-type : ARRAY_INDEX, 
                      |-type : NUM, value : 1, 
                  |-type : NUM, value : 4, 
              |-type : STATEMENTS, 
                |-type : STATEMENT, 
                  |-type : ASSIGN, 
                    |-type : ARRAY, 
                      |-type : ARRAY_INDEX, 
                        |-type : NUM, value : 2, 
                    |-type : NUM, value : 2, 
                |-type : STATEMENTS, 
                  |-type : STATEMENT, 
                    |-type : ASSIGN, 
                      |-type : ARRAY, 
                        |-type : ARRAY_INDEX, 
                          |-type : NUM, value : 3, 
                      |-type : NUM, value : 7, 
                  |-type : STATEMENTS, 
                    |-type : STATEMENT, 
                      |-type : ASSIGN, 
                        |-type : ARRAY, 
                          |-type : ARRAY_INDEX, 
                            |-type : NUM, value : 4, 
                        |-type : NUM, value : 3, 
                    |-type : STATEMENTS, 
                      |-type : STATEMENT, 
                        |-type : ASSIGN, 
                          |-type : ARRAY, 
                            |-type : ARRAY_INDEX, 
                              |-type : NUM, value : 5, 
                          |-type : NUM, value : 5, 
                      |-type : STATEMENTS, 
                        |-type : STATEMENT, 
                          |-type : ASSIGN, 
                            |-type : ARRAY, 
                              |-type : ARRAY_INDEX, 
                                |-type : NUM, value : 6, 
                            |-type : NUM, value : 9, 
                        |-type : STATEMENTS, 
                          |-type : STATEMENT, 
                            |-type : ASSIGN, 
                              |-type : ARRAY, 
                                |-type : ARRAY_INDEX, 
                                  |-type : NUM, value : 7, 
                              |-type : NUM, value : 10, 
                          |-type : STATEMENTS, 
                            |-type : STATEMENT, 
                              |-type : ASSIGN, 
                                |-type : ARRAY, 
                                  |-type : ARRAY_INDEX, 
                                    |-type : NUM, value : 8, 
                                |-type : NUM, value : 1, 
                            |-type : STATEMENTS, 
                              |-type : STATEMENT, 
                                |-type : ASSIGN, 
                                  |-type : ARRAY, 
                                    |-type : ARRAY_INDEX, 
                                      |-type : NUM, value : 9, 
                                  |-type : NUM, value : 8, 
                              |-type : STATEMENTS, 
                                |-type : STATEMENT, 
                                  |-type : FUNCCALL, 
                                    |-type : IDENT, variable : quicksort
                                    |-type : ARGS, 
                                      |-type : IDENT, variable : data
                                      |-type : ARGS, 
                                        |-type : NUM, value : 0, 
                                        |-type : ARGS, 
                                          |-type : NUM, value : 9, 
