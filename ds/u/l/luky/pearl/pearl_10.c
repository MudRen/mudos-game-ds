// Room: /u/l/luky/room/pearl_10.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short", HIG"�ï]���ਤ"NOR);
set("long", @LONG

[31m��[m
[41;31m�i[m��         �o�̬O�ï]���ਤ�C���F�O�ï]�n��A      �ġ�
[41;31m�i[m :��     ���_�O�ï]���C��観�@�ɤ馡���ؿv��    ��:   
[41;31m�i[m : :�j   �A���⪺�j�����ٱ��F�@�ө۵P(Sign)�C�A  �y: :   
[41;31m�i[m : :�j   ���n��O�@���ĩ��A�A�i�H�b���̶R���ĥH  �y: :  =
[41;31m�i[m :��     �Ƥ��ɤ��ݡC                              ��:  =
[41;31m�i[m��                                                   �á�
[31m��[m
LONG
);
set("exits", ([ /* sizeof() == 4 */
 "north" : __DIR__"pearl_11",
 "west" : __DIR__"pearl_33",
 "south" : __DIR__"pearl_34",
 "east" : __DIR__"pearl_9",
]));
set("item_desc",([
  "sign":"�۵P�W�g�۬n�C��K���|�Ӥj�r"HIY"�i�ѹD�D���j�C\n"NOR,
  "�۵P":"�۵P�W�g�۬n�C��K���|�Ӥj�r"HIY"�i�ѹD�D���j�C\n"NOR,
]));
set("no_clean_up", 0);
set("light",1);
create_door("west","����j��","east",DOOR_LOCKED,"red_key");
setup();

}
