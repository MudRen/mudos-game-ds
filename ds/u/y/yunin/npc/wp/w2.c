#include <ansi.h>

#include <weapon.h>

inherit BLADE;

void create()

{

set_name(HIR"�ƥ@�g�H" NOR ,({"crazy of blade","blade"}));

set("long","�o�O�Щ]�l�Ұt�a���Z���C\n");

set_weight(10000);

        if( clonep() )

                set_default_object(__FILE__);

        else {

set("unit", "��");

set("value",5000);

set("volume",3);

set("limit_str",10);

set("limit_con",10);

        }

set("wield_msg",HIB"$N��X�@��$n"HIB",�y�ɶ��Ů��M�����C\n");

set("unwield_msg", HIB"$N��U�⤤��$n"HIB", �Ů�ש��_�즳�����R�C\n");



set("combat_msg", ({

   HIR"$N�ϥX"HIB"�Щ]�|�M"HIW"��"HIY"�u"HIW"�Я}����"HIY"�v"HIR"�A���O��J�A���ݤf�M�����C\n\n"NOR,



   HIR"$N�ϥX"HIB"�Щ]�|�M"HIW"��"HIY"�u"BLK"�©]�L��"HIY"�v"HIR"�A�a�a���®�K��J$n"HIR"���餺�C\n\n"NOR,

   HIR"$N�ϥX"HIB"�Щ]�|�M"HIW"��"HIY"�u"HIG"�ѥ~���P"HIY"�v"HIR"�A�ֳt���M���J�F$n"HIR"�A�u��$n"HIR"�k�h�a�Ԥ��_�ӡC\n\n"NOR,







   HIR"$N�ϥX"HIB"�Щ]�|�M"HIW"��"HIY"�u"NOR""MAG"�Щ]"HIY"�v"HIR"�A�M��M���}�D�H����W�V$n"HIR"�r��A�u��$n"HIR"�k�h�L��A����ۧڡC\n\n"NOR,



}) );

init_blade(69);

setup();

}
