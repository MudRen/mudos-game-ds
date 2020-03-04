#include <ansi.h>
#include <path.h>
inherit ROOM;

string welcome = 
HIR"\n�@�@�@�@�@�z�w�w�w�w�w�w�w�w�w�w�w�w�{\n"
"�@�@�@�@�@�x�@�@�@�@�@�@�@�@�@�@�@�@�x\n"
"�@�@�@�@�@�x�@�@�w��Ө��ѫǡ�I�@�x\n"
"�@�@�@�@�@�x�@�@�@�@�@�@�@�@�@�@�@�@�x\n"
"�@�@�@�@�@�|�w�w�w�w�w�w�w�w�w�w�w�w�}\n\n"NOR;

void create()
{
        set("short", HIC"��"HIY"��"HIG"�M"HIM"��"HIR"��"HIW);
        set("long",
HIW"\n �o�̬O "HIC"�ڤۤC��"HIW" �̭� "YEL"Omaga"HIW" ��s�}�� "HIY"Chat"HIW" �M�� "HIY"Room"HIW"�A�p�G�Q\n"
" �n"HIG"���"HIW"�A�Ϊ̬O�A�u�Q�n��ѡA�Ӥ��Q�n�Q�H�n���ܡA�N�i�H�b�b�o��\n"
" �P�I\n\n"NOR
        );
        set("exits", ([
  "out" : TMR_PAST"area/inn_2f.c",
]));
//      set("outdoors", "universe");
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_cast", 1);
        set("no_exert", 1);
        set("no_recall", 1);
        set("light", 1);
        set("no_clean_up", 0);
        setup();
}

void init()
{
        tell_object(this_player(), welcome);
}
