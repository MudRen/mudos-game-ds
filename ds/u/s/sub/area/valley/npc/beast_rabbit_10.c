inherit NPC;                                                           
                                                                       
void create()                                                          
{                                                                      
        set_name("小白兔", ({"rabbit"}) );                             
        set("long",@LONG                                               
一隻毛茸茸的小白兔，在地上跳來跳去，相當的可愛。                       
LONG);                                                                 
        set("unit","隻");                                              
        set("race", "beast");                                          
        set("limbs", ({ "頭部", "身體","長長的耳朵","前腳","後腿"}));  
        set("verbs", ({ "crash" }));                                   
        set("age", 1);                                                 
        set("level",10);                                               
                                                                       
        setup();                                                       
}                                                                      
