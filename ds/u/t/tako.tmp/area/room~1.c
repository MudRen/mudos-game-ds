#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�}�]");
        set("long",@LONG
�o�̬O�@�Ӥ��|�ª��s�}�A�A�`�J�}�̡A�u���P�D�V�ӶV�t�A�����٦�
�r�~���n���A�A�߸̮`�ȷ��F�A�u�Q�������}�o�Ӥs�}�A�n���}�o�ɭԧA�o�{
�쨤�����@�y�J���A�A�ߦ��⮩����:��ӬO�o�Ӧb�o�����A�b�A�����P�ɡA��
�@�������q�A���Y�W���L,�A�~�F�@��..�C
LONG       );
        set("exits", ([ /* sizeof() == 1 */
  "down" :"/u/t/tako/area/room~2.c",
]));
        set("objects", ([ /* sizeof() == 1 */
       "/u/t/tako/statue.c" : 1,
        ]));
        set("outdoors","land");
    set("light",1);
        set("no_clean_up", 0);
       setup();
}

