#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit FORK;
void create()
{
              set_name(HIR "���V"NOR"��",({"devil-fire-fork","fire","fork"}));
              set("long","�o�O�@�������q��ӨӪ��١A�����٬`�|���ɪ��o�X���V�A�O�@���R���������١C\n");
              set_weight(5000);
              if( clonep() )
                      set_default_object(__FILE__);
              else {
                    set("unit", "��");
                    set("material", "iron");
                    set("value",1500);
set("replica_ob",
"/u/k/king/area/npc/wp/staff");

                    set("combat_msg", ({
"$N����"HIR"���V"NOR"�٥H�}�Ѥ��աA��$n���ܤߨ�h�C",
""HIR"���V"NOR"�٫_�X���V�N$n�����]��A$n�~�����b�a�W���y�N���A$N�@�n�g�ܡA�|�P�����V�P�ɱN$n���I�C"    }) );

          init_fork(10);
setup();
}
}



