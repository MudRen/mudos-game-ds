#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"���~�ϳ���");
        set("long", @LONG
�A�Q���J�o�@���ƪ����~���A�������U�Ө쩳�|�o�ͤ����
���A�A�V�ӶV��i�A�A���������F�L�h....
LONG
        );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);
        set("no_kill",1);
        setup();
}
