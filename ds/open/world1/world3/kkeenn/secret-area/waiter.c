#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�Q�G�H�ȩ�");
        set("long", @LONG
�o�O�a�U�������Q�G�H�ȴ̡A�b�o�̦��j�s���ӫȡA���G�i�H��D
�����p�ȴ̪��p�ܦh�A�Q�G�H�ȴ̬O�̪�Ѥf�O���ȴ̡A�ҥH�ӫȴ��
�ӤJ�A�i��O�����v�ݮ�^���ɪ����Y�A�b�o�̪��ȫȳ����|�j�n����
�A�n�����X�줣§�����ȤH�Q���]�D�H�F�X�h�ܦ��ĤQ�T�H�F�A�ӤW�O
�ӫȪ��𮧩СA�b�C���W����F�@�ӵ��C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "north":__DIR__"sec6.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/boss.c"     :1,
"/open/world3/tmr/basic/npc/hotelrobot.c"  :1,
]));

        setup();
        replace_program(ROOM);

}
