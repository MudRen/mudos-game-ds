#include <ansi.h> 
inherit ITEM;
void create()
{
set_name(HIY"���ª�����"NOR,({"statue"}));
set_weight(100);
set("value",0);
set("unit","�L");
set("long","�ǹк����������C\n");
set("no_get",1);
setup();
}

void init()
{
        add_action("do_clean","clean");
}

int do_clean(string str)
{

object me = this_player();
     if(this_object()->query_temp("cleaned") != 0) return 1;
     if( str !="����") return notify_fail("what?\n"NOR);
        { 
       if( !query("start"))
        {
        message_vision(HIR"$N�p���l�l�����������W�����I�C\n"+NOR,me);
        message_vision(HIR"��M�����ʤF�_�ӡA�����Ѷ}�ʦL�����I�I\n"+NOR,me);
        set("start", 1);
        call_out("evil_msg",4);
        } else {
         return notify_fail("�����̰ʤ��C\n");
     } 
 }
return 1;

}

int evil_msg()
{
   message("world:world1:vision",
HIW"\n\t����@�D�����{�L���\n\n\t"HIY"�ⶳ�x���������D�G"HIG"���D���ٸ{���A�Q������w�X�������ԡI�I\n\n\n"NOR,users());
  call_out("getin_msg",3);
} 
int getin_msg(object me)    
{
    object mob;
    me=this_player();
    mob=this_object();

    message_vision(HIR"�C���𪺤d�~���еd���ӹL�ӡI�I\n"NOR,me);
    set("item_desc",([
        "����":"�������W�w�L����ǹСC\n",
        ]));
    me->move(__DIR__"4f_1");
    mob=new(__DIR__"npc/evil3.c");
    mob->move(__DIR__"4f_1");
    mob->kill(me); 
    destruct(this_object());     
  return 1;
}

