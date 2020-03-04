#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
   set("short",HIC"�_�Z��"NOR"��"HIG"�p��"NOR);
   set("long",@LONG
�Ө�o�̡A���G�w�g������Y�F�C���O�A�o�S���ݨ줰��r
�~�������Ǫ��A�u���A���e���@�ӤQ����j�����Y�A���O�o����
�Y�n���}���G�n��ܤj���O��E�E
LONG);
   set("exits",([
       "south":__DIR__"town30",
       ]));
   set("objects", ([
       ])); 
   set("item_desc",([
       "�j��" :NOR"�@���Q�����j���۶��A�n����(move)�ݰ_�ӫܧx���C\n"NOR]));     
   set("outdoors","land");
   set("no_clean_up", 0);
   setup();
}     

void init()
 {
   add_action("do_move","move");
 }

int do_move(string arg)
{
   string arg1;
   object me,room;
   me = this_player();
   room = this_object();

     if(!arg) 
        return notify_fail("�A�n���ʤ���H\n");
     if((arg!="�j��"))
        return notify_fail("�o�̨èS���o�تF��C\n");
     if(me->query("str") < 70 )
        return notify_fail(NOR"�A���O�𤣰��A�L�k���ʥ۶��C\n"NOR); 
     if(me->is_busy() ) 
        return notify_fail("�A���b���A�S�ŰաC\n");
     if(arg == "�j��" && room->query("open_ok") != 1) 
     {
        message_vision(HIG"$N��j�۲��}�A�o�o�{�a�W�X�{�@�Ӥj�}�I�̭��n�������C\n"NOR,me);
        me->start_busy(3);
        add("exits/down",__DIR__"entrance");
        room->set("open_ok",1);
     }
     else
     { message_vision(NOR"�j�ۤw�g�Q���}�F...\n"NOR,me); }
 return 1;
}

void reset()
{
    set("exits", ([
        "south"  : __DIR__"town30",
         ]));
    this_object()->delete("open_ok");
    ::reset();
}

