// Room: /u/l/luky/room/pearl_4.c
inherit ROOM;
void create()
{
set("short","[1;32m�ï]���ਤ[m");
set("long", @LONG

�ġ�                                                   ����
   :��        �o�̬O�ѹp�����F�n���A����           ��: ��
   : :�j    �ƨӷL�L�����死�C�q�o�̩��_�O         �y: : ��
=  : :�j    �ï]�F��A����h�O���x���ï]�n         �y: : ��
=  :��      ��C                                     ��: ��
�á�                                                   ����

LONG
);
set("objects",([
__DIR__"npc/pagurian":2,
]));
set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"pearl_5",
  "north" : __DIR__"pearl_3",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
