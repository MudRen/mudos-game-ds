//�t�Ϭ��ʲĤ@�W �ӯT(ttoopp) §�� -by tmr-

#include <ansi.h>
#include <armor.h>
inherit PANTS;

void create()
{
          set_name(HIR "�g�s" HIC "��z��" NOR ,({ "ttoopp pants","pants"}) );
        set("long",
"�t�Ϭ��ʲĤ@�W �ӯT�ұo����§���C\n"
"�o�O�@��W��¸�ۨg�s�Ϯת���z��,���G�N��ۤ���N�q.........\n"
);
        set_weight(1200);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "fur");
                set("unit", "��" );
                set("value",2500);
                set("valme",3);
                set("no_sac",1);
                set("armor_prop/armor", 10);
                set("armor_prop/con",1);
        }
        setup();
}

int query_autoload() { return 1; }


