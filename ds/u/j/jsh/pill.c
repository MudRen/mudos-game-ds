#include <ansi.h> 
inherit ITEM;
inherit F_PILL; 
void create()
{
        set_name(HIW"������"NOR, ({ "score pill", "pill" }));
        set("long",
"�i�H���C�ݩʪ��@���ĤY�A�b�Y���e�A�n�Ҽ{�M����I \n"
"�ϥΤ�k�G "HIC"reduce <�ݩ�> \n"NOR

);
        set_weight(500);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
                set("unit", "��");
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
        if(!arg || arg=="") return notify_fail("�A�Q�n���C����H\n"); 
        {
        if(arg=="str") 
        {
          me->query_str()-2;
          me->save();   
          tell_object(me,HIC"�A���O�q���C�F���I�C\n"NOR);
          destruct(this_object());
        } else if(arg=="con") 
               {
               me->query_con()-2;
               me->save();   
               tell_object(me,HIC"�A����議�C�F���I�C\n"NOR);
               destruct(this_object());
               } else if(arg=="int") 
                      {
                      me->query_int()-2;
                      me->save();   
                      tell_object(me,HIC"�A�����z���C�F���I�C\n"NOR);
                      destruct(this_object());
                      } else if(arg=="dex") 
                             {
                             me->query_dex()-2;
                             me->save();   
                             tell_object(me,HIC"�A���ӱ����C�F���I�C\n"NOR);
                             destruct(this_object()); 
                             } else return 0; 
        }
        return 1;
}
     
