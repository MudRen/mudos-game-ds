#include <ansi.h>
inherit ITEM;
void create()
{
set_name(HIR"RU486"NOR,({"pill"}) );
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
me->set("env/msg_mout",HIC"�a�W���M�}�F�@�Ӥj�}"NOR"�A"HIR"$N�j�s�@�n:�u���O�U�઺�v�A"HIM"�}�̭��X"HIW"�@�W�r�k"HIB"�A��$N���m���F�C\n"NOR);
me->set("env/msg_min",HIY"�ѤW�X�{���СA"HIR"�@�W�r�k�j��:"HIC"�u�����{�F�A�٤��W�Y�A"HIR"�䦺�v\n"NOR);
me->set("env/msg_clone",HIC"$N�R�ʤ�W��"HIM"�·t�]�k��"HIW"$n�@�}���{�N�ܤF�X��.\n"NOR);
me->set("env/msg_dest",HIW"$N�L��"HIM"��䪺���۩G�y"HIR"�@�����y�V$n���F�L�h"HIC"�F���@�n�ܦ��@��o��\n"NOR);
write(HIC"�A�Y�U�@��"HIR"�]�k"HIW"�p"HIC"�ĤY"NOR",�y�ɥ����o�X"HIW"�ե�\n"NOR);
destruct(ob);return 1;}


