#include <ansi.h> 
inherit ITEM;
void create()
{
set_name("�@�����U��"HIY"�o�O"NOR,({"lamp"}));
set_weight(100);
set("value",0);
set("unit","��");
set("long","���U�_���o�O�C\n");
setup();
}

void init()
{
        add_action("do_fire","fire");
}

int do_fire(string str)
{

object me = this_player();
     if(this_object()->query_temp("fired") != 0) return 1;
     if( str !="�}�O") return notify_fail("what?\n"NOR);
    
        { 
       if( !query("start"))
        {
        message_vision(HIR"$N�I�i���O�A�w�w���I�_�F�����O�C\n"+NOR,me);
        message_vision(HIR"�٨����A�����󤣰����n�̡A���A�t�I������}�I�I\n"+NOR,me);
        set("start", 1);
        call_out("evil_msg",4);
        } else {
         return notify_fail("�������b�|��C\n");
     } 
 }
return 1;

}

int evil_msg()
{
   message("world:world1:vision",
HIW"\n�b����������A���G�b�i�{�@���F���_�������A�u���ѪŬ�������.........\n\n\n"NOR,users());
  call_out("evil_msg2",3);
} 
int evil_msg2()
{
 message("world:world1:vision",HIC"\n����"NOR+CYN"���B�̪������D�����n�e�����Z�L�C\n\n"NOR,users());
  call_out("evil_msg_last",7);
}

int evil_msg_last()
{
  object me=this_player();message("world:world1:vision",HIR"\n�C���𪺬Y�����������d���F�_�ӡA�K�j�n�q�s�ۡG���Z�ڲM�v�A���ڵ�����H\n\n\n"NOR,users());
  call_out("getin_msg",3,me);
  set("start", 0);
  delete("start"); 
}


int getin_msg(object me)    
{
    object mob;
    me=this_player();
    mob=this_object();

    message_vision(HIY"�C���𪺤k�ʤ��̽w�w�����F�L�ӡA�K��A�j�}���١I�I\n"NOR,me);
    set("item_desc",([
        "�}�O":"���O�w�Q�I�ۡC\n",
        ]));
    mob=new(__DIR__"npc/evil1.c");
    mob->move(__DIR__"1f_6");
    mob->kill(me); 
    destruct(this_object());       return 1;
}


