// Room: /u/l/luky/room/pearl_6.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"�ï]�n��"NOR);
set("long", HIW"\n
�ġ�         "NOR"�@����o�̡A�A���T�Q�_�p�ɭԥ��a�@�_"HIW"      �ġ�
   :��     "NOR"�h�}�󪺨��ѿ��ķP�A���Ӥp�Ĥl�@�˪��|"HIW"    ��:   
   : :�j   "NOR"�B�i��C�������D�A�ө����H�s�A���A��"HIW"  �y: :   
=  : :�j   "NOR"�F�o�ӥ@�ɪ���{�P�ɤO�C���_���O����j"HIW"  �y: :  =
=  :��     "NOR"�D�A�n�観��"HIM"����"NOR"�C��D�V�F��詵���C"HIW"      ��:  =
�á�                                                   �á�
	"NOR);
set("objects",([
__DIR__"npc/sightseer":2,
]));
set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"pearl_7",
  "north" : __DIR__"pearl_24",
  "south":__DIR__"pearl_36",
  "east" : __DIR__"pearl_5",
]));
set("no_clean_up", 0);
set("light",1);
setup();
load_object(__DIR__"temp/rest");
load_object(__DIR__"npc/guest");
}
