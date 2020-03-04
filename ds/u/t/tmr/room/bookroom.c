// Room: /u/t/tmr/room/bookroom.c
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�p�_�_���ѩ�");
        set("long", @LONG
�@��i���ݩж��A�Ѻ��Ǫ��W�Q�ѡB�e�A�A�Nı�o
�����D�H�w�O�ӷR�n�������M�h�A�u�D���~���n�ڳڡA
�@�\�����M�o���ǩ��G�A�O�H���M��n�A���e���i��
�A���ɡA�A�ݤF�N�Q�n�n�a���b�W����(rest)�C
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
	  "north" : (: look_door,     "north" :),
	]));

        set("exits", ([ /* sizeof() == 1 */
	  "north" : __DIR__"t1.c",
	]));

       create_door("north", "���", "south", DOOR_CLOSED);
        set("objects", ([ /* sizeof() == 1 */
	  __DIR__"npc/dragon" : 1,
	]));
        
	set("no_clean_up", 0);
        setup();
}

void init()
{
	add_action("do_rest","rest");
}
int do_rest()
{
  object me;
  me=this_player();
  tell_object(me, HIW "�A�����F�i�y�A�u�z~~~~��~~~~~�v���j�j�a���F�@�ӫ���.\n\n\n" NOR );
  tell_object(me, HIW "�����@���A�H�Y�N�b���n�A�������ɺεۤF.....\n\n" NOR );
  tell_object(me, HIB "zzzZZZZzzz......\n\n\n" NOR );
  tell_object(me, HIB "�i�Q��g�L�j......\n" NOR );
  tell_object(me, HIW "�A�C�}�F�����A��A�믫�^�_�F�A�A�ӥ���F...\n" NOR );
  return 1;
}
