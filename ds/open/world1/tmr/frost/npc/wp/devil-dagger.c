#include <ansi.h>
#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name(HIR "���F�P��" NOR,({"devil dagger","dagger"}) );
        set("long",@LONG
    �o�O�@�������P���A�P�W�N��b���ª��]�ߤ]�ല�o�X���H�ө���
�����A���`�W��ۼƺا��]���ҼˡA���u��ӦӨϱo�C�L���]���y����
�ݦp�͡A���G�H�ɷ|�ĥX�Ӷˮ`�A�@�ˡC
LONG
);
         set_weight(2500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
                set("value",5000);
        }
        set("light",1);
        set("weapon_prop/dex",1);
        set("weapon_prop/bio",1);
        set("weapon_prop/sou",1);
        set("limit_level",25);
        set("limit_dex",50);
        init_dagger(38);
        set("backstab_bonus",40); //�ʤ���
        setup();        
}

void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}

