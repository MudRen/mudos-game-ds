//2006.5.30 add by whoami
#include <ansi.h>
inherit ITEM;
inherit BOX_LOG;

void create()
{
    set_name(HIG"�Z���c"NOR,({"weapon box","box"}));
        set("unit", "��");
        set("long",@LONG
  �@�ӥΨө�m�O�s���h�Z�����K�c�C�A�i�H��öQ���Z����b�c�̫O
  �s�άO�q�c�l�����X�A�ҳ߷R���Z���C
 
  ��F��: put [�F��] in weapon box
  ���F��: get [�F��] from weapon box

  �o�ӽc�l���ۯS���\��:
         ** checkuse 'box or shelf's id' {-w|-l|-m}
         ** cleanup 'box or shelf's id' {get|put|all}

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
        set_max_capacity(400); //2003.4.16  10000 -> 400  by ksj
        set("club_id", "moon");
        set("demand_level", 3);
        set("access_log",1);
        setup();
}

