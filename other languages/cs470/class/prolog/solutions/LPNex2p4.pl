/* LPNex2p4.pl   */

word(astante,  a,s,t,a,n,t,e).
word(astoria,  a,s,t,o,r,i,a).
word(baratto,  b,a,r,a,t,t,o).
word(cobalto,  c,o,b,a,l,t,o).
word(pistola,  p,i,s,t,o,l,a).
word(statale,  s,t,a,t,a,l,e).

crossword(V1N,V2N,V3N,H1N,H2N,H3N) :- word(V1N,V1L1, V1L2,V1L3,V1L4,V1L5,V1L6, V1L7 ),
                                 word(V2N,V2L1, V2L2,V2L3,V2L4,V2L5,V2L6, V2L7 ),
                                 word(V3N,V3L1, V3L2,V3L3,V3L4,V3L5,V3L6, V3L7),
                                 word(H1N,H1L1, H1L2,H1L3,H1L4,H1L5,H1L6, H1L7 ),
                                 word(H2N,H2L1, H2L2,H2L3,H2L4,H2L5,H2L6, H2L7 ),
                                 word(H3N,H3L1, H3L2,H3L3,H3L4,H3L5,H3L6, H3L7 ),
                                 H1L2 = V1L2, H1L4 = V2L2, H1L6 = V3L2,
                                 H2L2 = V1L4, H2L4 = V2L4, H2L6 = V3L4,
                                 H3L2 = V1L6, H3L4 = V2L6, H3L6 = V3L6.                              
								
							
                                 								
																
/* ?-crossword(V1,V2,V3,H1,H2,H3).  */															