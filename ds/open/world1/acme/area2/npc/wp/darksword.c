#include <weapon.h>
#include <ansi.h>
inherit SSERVER;
inherit SWORD;

void create()
{
        set_name(HIR "�խ߼C" NOR,({"you ming sword","you","ming","sword"}) );
        set("long",
        "�o�O�@�ⴲ�o�۳��𪺧��C�A�C���z���A�����~�C\n"
        "�o��C�ǻ��O�ѤѴݨ��Цb�n�s��A�B�A�M�V�쪺\n"
        "���K���y�Ӧ��A�ڻ����y���C�A��O�F�L�ƪ��H�O\n"
        "�M�]�O�A�M�C�C�|�Q�E�~�������A�Ӧ����|�@�L��\n"
        "���C�C\n"
        );
        set_weight(4000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
        set("value",8000);
                set("limit_str",20);
		set("limit_con",30);
		set("volume",3);
                set("limit_int",10);
                set("limit_dex",5);
		set("limit_skill",70);
        }
   set("weapon_prop/dodge",7);
    set("weapon_prop/bar",1);
	set("weapon_prop/bio",1);
    set("weapon_prop/tec",-2);
        init_sword(60);
        setup();        
}
