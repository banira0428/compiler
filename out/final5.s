 
 
 
 
 
 
  
  
  
  
  
  
  
  

 
   
 


 
 
       
 
 
    .text
main:
|-type : PROGRAM, 
  |-type : DECLARATIONS, 
    |-type : ARRAY_DEFINE, 
      |-type : ARRAY, 
    |-type : DECLARATIONS, 
      |-type : ARRAY_DEFINE, 
        |-type : ARRAY, 
      |-type : DECLARATIONS, 
        |-type : ARRAY_DEFINE, 
          |-type : ARRAY, 
        |-type : DECLARATIONS, 
          |-type : DEFINE, 
            |-type : DECL_IDENTS, 
              |-type : IDENT, variable : i
          |-type : DECLARATIONS, 
            |-type : DEFINE, 
              |-type : DECL_IDENTS, 
                |-type : IDENT, variable : j
            |-type : DECLARATIONS, 
              |-type : DEFINE, 
                |-type : DECL_IDENTS, 
                  |-type : IDENT, variable : k
  |-type : STATEMENTS, 
    |-type : STATEMENT, 
      |-type : ASSIGN, 
        |-type : ARRAY, 
          |-type : ARRAY_INDEX, 
            |-type : ARRAY_INDEX, 
              |-type : NUM, value : 0, 
            |-type : NUM, value : 0, 
        |-type : NUM, value : 1, 
    |-type : STATEMENTS, 
      |-type : STATEMENT, 
        |-type : ASSIGN, 
          |-type : ARRAY, 
            |-type : ARRAY_INDEX, 
              |-type : ARRAY_INDEX, 
                |-type : NUM, value : 0, 
              |-type : NUM, value : 1, 
          |-type : NUM, value : 2, 
      |-type : STATEMENTS, 
        |-type : STATEMENT, 
          |-type : ASSIGN, 
            |-type : ARRAY, 
              |-type : ARRAY_INDEX, 
                |-type : ARRAY_INDEX, 
                  |-type : NUM, value : 1, 
                |-type : NUM, value : 0, 
            |-type : NUM, value : 3, 
        |-type : STATEMENTS, 
          |-type : STATEMENT, 
            |-type : ASSIGN, 
              |-type : ARRAY, 
                |-type : ARRAY_INDEX, 
                  |-type : ARRAY_INDEX, 
                    |-type : NUM, value : 1, 
                  |-type : NUM, value : 1, 
              |-type : NUM, value : 4, 
          |-type : STATEMENTS, 
            |-type : STATEMENT, 
              |-type : ASSIGN, 
                |-type : ARRAY, 
                  |-type : ARRAY_INDEX, 
                    |-type : ARRAY_INDEX, 
                      |-type : NUM, value : 0, 
                    |-type : NUM, value : 0, 
                |-type : NUM, value : 5, 
            |-type : STATEMENTS, 
              |-type : STATEMENT, 
                |-type : ASSIGN, 
                  |-type : ARRAY, 
                    |-type : ARRAY_INDEX, 
                      |-type : ARRAY_INDEX, 
                        |-type : NUM, value : 0, 
                      |-type : NUM, value : 1, 
                  |-type : NUM, value : 6, 
              |-type : STATEMENTS, 
                |-type : STATEMENT, 
                  |-type : ASSIGN, 
                    |-type : ARRAY, 
                      |-type : ARRAY_INDEX, 
                        |-type : ARRAY_INDEX, 
                          |-type : NUM, value : 1, 
                        |-type : NUM, value : 0, 
                    |-type : NUM, value : 7, 
                |-type : STATEMENTS, 
                  |-type : STATEMENT, 
                    |-type : ASSIGN, 
                      |-type : ARRAY, 
                        |-type : ARRAY_INDEX, 
                          |-type : ARRAY_INDEX, 
                            |-type : NUM, value : 1, 
                          |-type : NUM, value : 1, 
                      |-type : NUM, value : 8, 
                  |-type : STATEMENTS, 
                    |-type : STATEMENT, 
                      |-type : FOR, 
                        |-type : FOR_ASIGN, 
                          |-type : ASSIGN, 
                            |-type : IDENT, variable : i
                            |-type : NUM, value : 0, 
                        |-type : FOR_COND, 
                          |-type : LT, 
                            |-type : IDENT, variable : i
                            |-type : NUM, value : 2, 
                        |-type : FOR_EXPR, 
                          |-type : INC_EXPR, 
                            |-type : IDENT, variable : i
                        |-type : STATEMENTS, 
                          |-type : STATEMENT, 
                            |-type : FOR, 
                              |-type : FOR_ASIGN, 
                                |-type : ASSIGN, 
                                  |-type : IDENT, variable : j
                                  |-type : NUM, value : 0, 
                              |-type : FOR_COND, 
                                |-type : LT, 
                                  |-type : IDENT, variable : j
                                  |-type : NUM, value : 2, 
                              |-type : FOR_EXPR, 
                                |-type : INC_EXPR, 
                                  |-type : IDENT, variable : j
                              |-type : STATEMENTS, 
                                |-type : STATEMENT, 
                                  |-type : ASSIGN, 
                                    |-type : ARRAY, 
                                      |-type : ARRAY_INDEX, 
                                        |-type : ARRAY_INDEX, 
                                          |-type : IDENT, variable : i
                                        |-type : IDENT, variable : j
                                    |-type : NUM, value : 0, 
                    |-type : STATEMENTS, 
                      |-type : STATEMENT, 
                        |-type : FOR, 
                          |-type : FOR_ASIGN, 
                            |-type : ASSIGN, 
                              |-type : IDENT, variable : i
                              |-type : NUM, value : 0, 
                          |-type : FOR_COND, 
                            |-type : LT, 
                              |-type : IDENT, variable : i
                              |-type : NUM, value : 2, 
                          |-type : FOR_EXPR, 
                            |-type : INC_EXPR, 
                              |-type : IDENT, variable : i
                          |-type : STATEMENTS, 
                            |-type : STATEMENT, 
                              |-type : FOR, 
                                |-type : FOR_ASIGN, 
                                  |-type : ASSIGN, 
                                    |-type : IDENT, variable : j
                                    |-type : NUM, value : 0, 
                                |-type : FOR_COND, 
                                  |-type : LT, 
                                    |-type : IDENT, variable : j
                                    |-type : NUM, value : 2, 
                                |-type : FOR_EXPR, 
                                  |-type : INC_EXPR, 
                                    |-type : IDENT, variable : j
                                |-type : STATEMENTS, 
                                  |-type : STATEMENT, 
                                    |-type : FOR, 
                                      |-type : FOR_ASIGN, 
                                        |-type : ASSIGN, 
                                          |-type : IDENT, variable : k
                                          |-type : NUM, value : 0, 
                                      |-type : FOR_COND, 
                                        |-type : LT, 
                                          |-type : IDENT, variable : k
                                          |-type : NUM, value : 2, 
                                      |-type : FOR_EXPR, 
                                        |-type : INC_EXPR, 
                                          |-type : IDENT, variable : k
                                      |-type : STATEMENTS, 
                                        |-type : STATEMENT, 
                                          |-type : ASSIGN, 
                                            |-type : ARRAY, 
                                              |-type : ARRAY_INDEX, 
                                                |-type : ARRAY_INDEX, 
                                                  |-type : IDENT, variable : i
                                                |-type : IDENT, variable : j
                                            |-type : PLUS, 
                                              |-type : ARRAY, 
                                                |-type : ARRAY_INDEX, 
                                                  |-type : ARRAY_INDEX, 
                                                    |-type : IDENT, variable : i
                                                  |-type : IDENT, variable : j
                                              |-type : MUL, 
                                                |-type : ARRAY, 
                                                  |-type : ARRAY_INDEX, 
                                                    |-type : ARRAY_INDEX, 
                                                      |-type : IDENT, variable : i
                                                    |-type : IDENT, variable : k
                                                |-type : ARRAY, 
                                                  |-type : ARRAY_INDEX, 
                                                    |-type : ARRAY_INDEX, 
                                                      |-type : IDENT, variable : k
                                                    |-type : IDENT, variable : j