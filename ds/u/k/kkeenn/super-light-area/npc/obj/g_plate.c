inherit ITEM;
void create() 
{
          set_name("金牌",({"gold plate","plate"}) );
           set("long","一面有電子管線的金牌，看來價值應該不便宜！\n");
               set("value",2000);
          set_weight(2000);
          if(clonep() ) 
            set_default_object(__FILE__);
           else {
          set("unit","面");
}
setup();
}
