#include <ansi.h>
inherit ITEM;
void create()
{
set_name(HIR"�]�k"HIW"�p"HIC"�ĤY"NOR,({"pill"}) );
set("pill","LONG");
set_weight(1);
if( clonep() )
set_default_object(__FILE__);
else{set("unit","��");set("value",50000); }
setup();
}

void init()
{add_action("do_eat","eat");}

int do_eat(string arg)
{object me = this_player();object ob = this_object();
if( !this_object() ) return 0;if( !this_object()->id(arg) ) return 0;
me->set("env/msg_mout",HIW"$N���ʤ�W��"HIB"�·t�]�M"NOR","HIY"�@�}���{,"HIR"$N������"HIC"�L�v�L��.\n"NOR);
me->set("env/msg_min",HIC"�F���@�n"HIW"�@�}���{"HIY"���M$N"HIM"���F�X��.\n"NOR);
me->set("env/msg_clone",HIC"$N�R�ʤ�W��"HIM"�·t�]�k��"HIW"$n�@�}���{�N�ܤF�X��.\n"NOR);
me->set("env/msg_dest",HIW"$N�L��"HIM"��䪺���۩G�y"HIR"�@�����y�V$n���F�L�h"HIC"�F���@�n�ܦ��@��o��\n"NOR);
write(HIC"�A�Y�U�@��"HIR"�]�k"HIW"�p"HIC"�ĤY"NOR",�y�ɥ����o�X"HIW"�ե�\n"NOR);
destruct(ob);return 1;}

