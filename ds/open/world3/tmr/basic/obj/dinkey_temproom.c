#include <path.h>
inherit ROOM;
int do_move(int flag);

void create()
{
        set("short", "�q����");
        set("long", @LONG
�A���B�b�¥@�ɹq���̡A�G�ǻᬰ�}�ꪺ�y�ȤW�u���}�}�������X��
�H�B�Χ��ν��������۹q���o�ʡC�����b�N�������ŽաA���Aı�o�Q���
��l�n�n���𮧤@�f�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "out" : FUTURE+ "tmr/basic/train_station1",
        ]));
        set("world", "future");
        set("light",1);
        set("no_clean_up", 0);

        setup();
}

int do_move(int flag)
{
        tell_room(__DIR__"dinkey_temproom","�͹͹͡I�q���ֳt�����W�����A���t���}�V�ت��a\n");
        tell_room(__DIR__"dinkey_temproom","\n�Aı�o�����@�}�̰ʡA�ͪ��@�n�A�����S�}�ҤF...\n");
        if(flag==1)
                set("exits", ([ "out" : "/u/s/superbug/train/3.c" ]));
        else 
                set("exits", ([ "out" : FUTURE+ "tmr/basic/train_station1"]));

        return 1;
}


