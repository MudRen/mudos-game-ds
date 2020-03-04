#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�Ѥѥj��"NOR);

 set("long",@LONG 
�A�O�ɤd���U�W, �ש��b�o���ǻ���������e��, �A�ߤ�
���P�ʨϧA�X�G�n�y�U�\��, �A�|����F�沴�e������, �u����
�ڿ������, �K���a�a, �������G�z���F��, �G�M�n�@�ʯ���! 
�N�b�A�ߤ����P�ʩ�o�ʯ��줧��, �A���M�|�Y�o�{��K�W���G
���I�޲�?
LONG);
set("exits",([ "southwest":__DIR__"tree5",
    ]));
 set("item_desc",([
        "��K":"�A�|�Y�����Y�W����K, �o�{�b�ڳ����@�鲪��, 
���G���H�W�U�o�ھ�K, �A�۫H�H�A�����\\��¦, �n���W��K�ä��x��.\n"
    ]));

 set("no_clean_up",0);
 set("outdoors","forest");
 setup();
}
void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
       object me=this_player();
       if (!arg || arg =="") return notify_fail("�A�n������H\n"); 
       if( me->is_busy() ) return notify_fail("�A�٦b���I\n");
       if (arg != "��K") return notify_fail("�A�n������H\n"); 
       if (random(me->query_skill("dodge")) > 55 || me->query("class1") == "skyowl"){
       message_vision("�u��$N���l�@�D, ���M���W�F��K! !\n",me);
         me->move(__DIR__ "tree_2F1");
       } else {
       message_vision("����$N�p��V�O, �l�׵L�k���W��K..\n",me);
       }
       me->start_busy(3);
       return 1;
}
