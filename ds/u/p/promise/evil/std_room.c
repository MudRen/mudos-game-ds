#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"���]��ɳB"NOR);
        set("long", "
���a�O���P�]����ɡA�ⰼ�����u�æb�u�@�ۡA�����@�Ƕ����H
���i�J�C���U��N�O���]��Ať�@�H�Ǩ��A�Z�O���J���]��o�����k
�����H�ί��A���L�k�����Ӱh�����X�A�i�����]�쪺�i�ȡA�������P
���Z�L�n�⤣�������C
");
 
        set("light", 1);
        set("objects", ([ /* sizeof() == 2 */
 __DIR__"npc/e-guard" : 1,
 __DIR__"npc/godguard" : 1,
]));
        set("item_desc", ([
        "�����W" : "���W�����]�쪺�N��A�H�x�����]�쪺�·t�C�b�W�l�������@�ʤf�A�����O�_�i��J���~�H\n",
                
        ]));
        setup();
}

void init()
{
        add_action("do_putin","putin");
}

int do_putin(string arg)
{

object me = this_player();
object mirror;

      if(!arg || arg!="�ʤf") return notify_fail("�A�n��J����?\n");
      if(!objectp(mirror=present("evil mirror",me) ) )
       return notify_fail("�n��J����? \n");

        { 
       if( !query("start"))
        {
        message_vision(HIR"$N��J�F���s���A�j�a��M���ܡC\n"+NOR,me);
        message_vision(HIR"��M���@�D������ģ���a�A�������{�{�A���A�������y�ɵL�k�i�}�I\n"+NOR,me);
        set("start", 1);
        call_out("evil_msg",4);
        } else {
         return notify_fail("���t�����w���}�C\n");
     } 
 }
return 1;

}

int evil_msg()
{
   message("world:world1:vision",
HIW"\n�s�Y"HIW+BLK"�a�ʡA�@�D����ģ�����~�{�{�b�Y��...............\n\n\n"NOR,users());
  call_out("evil_msg2",3);
} 
int evil_msg2()
{
 message("world:world1:vision",HIC"\n����"NOR+CYN"���]��̪������D�����n�e�����Z�L�C\n\n"NOR,users());
  call_out("evil_msg_last",7);
}

int evil_msg_last()
{
  object me=this_player();message("world:world1:vision",HIB"���]���"HIW"�j�n�����"HIG+me->query("name")+HIW"�H�S�G"HIR"��A��J���]�쪺���ѡA�j�~�K�O�A���Ҥ�I�I\n\n\n"NOR,users());
  call_out("getin_msg",3,me);

  set("start", 0);
  delete("start");
}


int getin_msg(object me)    
{
    me=this_player();

    message_vision(HIR"�u��������~��ģ��$N�A���趡$N�H�۬����C�C���h���A���������F�I�I\n"NOR,me);
    me->move(__DIR__"room1");     
    call_out("close_msg",20,me);
    return 1;
}
int close_msg(object me)
{
    message("world:world1:vision",HIY"\n\t�C�C���j�a�S��_�F�H�������M�P���R�F�C$�I\n"NOR,me);
    return 1;
}

