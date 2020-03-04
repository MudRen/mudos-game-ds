#include <ansi.h> 
inherit ITEM;
inherit F_PILL; 
void create()
{
        set_name(HIW"渾元丹"NOR, ({ "score pill", "pill" }));
        set("long",
"可以降低屬性的一種藥丸，在吃之前，要考慮清楚喔！ \n"
"使用方法： "HIC"reduce <屬性> \n"NOR

);
        set_weight(500);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
        }
        set("value", 10000);
        setup();
} 

void init()
{
     add_action("do_reduce","reduce");
}
int do_reduce(string arg)
{
    object me=this_player();  
/*
    int str,con,intt,dex;
    str=me->query_str();
    con=me->query_con();
    intt=me->query_int();
    dex=me->query_dex(); 
*/   
        if(!arg || arg=="") return notify_fail("你想要降低什麼？\n"); 
        {
        if(arg=="str") 
        {
          me->query_str()-2;
          me->save();   
          tell_object(me,HIC"你的力量降低了兩點。\n"NOR);
          destruct(this_object());
        } else if(arg=="con") 
               {
               me->query_con()-2;
               me->save();   
               tell_object(me,HIC"你的體質降低了兩點。\n"NOR);
               destruct(this_object());
               } else if(arg=="int") 
                      {
                      me->query_int()-2;
                      me->save();   
                      tell_object(me,HIC"你的智慧降低了兩點。\n"NOR);
                      destruct(this_object());
                      } else if(arg=="dex") 
                             {
                             me->query_dex()-2;
                             me->save();   
                             tell_object(me,HIC"你的敏捷降低了兩點。\n"NOR);
                             destruct(this_object()); 
                             } else return 0; 
        }
        return 1;
}
     
