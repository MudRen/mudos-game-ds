#include <room.h>;
#include <ansi.h>;
inherit ROOM;
void create()
{
      set("short",MAG"���K���S����"NOR);
      set("long",@LONG
�o�̪��O�@�ӯ��K���ж�, ���q���H�O���H�o�{�o�̪����K��, �A��
�M�o�{���@�ӥ����R�����޲����k�H�����b�o�̱i�}�j�L��A�S�X������
��, �|�P��ۤ@�c�@�c���j��c�l, �Ů𤤥R�����@�ѿ@�p�����Ĩ��C
LONG);
set("exits",([
     "north":__DIR__"4.c",
]) );
        set("world", "future"); 
set("objects", ([
__DIR__"weapon/weapon-man.c":   1,
]) );
setup();
replace_program(ROOM); 
}
