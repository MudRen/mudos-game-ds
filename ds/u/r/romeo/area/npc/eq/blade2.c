#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
              set_name(HIW"���v�M"NOR,({"light blade","blade"}));
              set("long","�@���Ĺ�����v�M�A�|�o�X�ȥզ���v.\n");
              set_weight(3000);
              if( clonep() )
                      set_default_object(__FILE__);
              else {
                    set("unit", "��");
                    set("value",1000);
                    set("material","iron");
                 }
                 init_blade(10);
set("combat_msg", ({    //�����T�� $N�O�ۤv $n�O��� $l �O�����𳡦� $w�O�Z���
                "$N�ⴤ$w�A�u���ȥզ�v���@�{�A�K��$n���Y���@��\n",
                "$N��$w��$n���{�l�����a�@Ѷ�A�y��$n��y�j�`�A�Q��$N�y�W\n",
                "$N��$w��$n���}�򳡨�h�A���G$n�h���z�z�j�s\n",
                "$N�N$w�@�Ϯ��A�K�V$n���ⳡ���\n",
                "$N�j�s�G�u��!��!�v�A��$n�ѤW���U�@�j��\n",
                "$N��$w��$n���{�l�����a�@Ѷ�A�y��$n��y�j�`�A�Q��$N�y�W\n",
                "$N��$w��$n���}�򳡨�h�A���G$n�h���z�z�j�s\n",
                "$N�N$w�@�Ϯ��A�K�V$n���ⳡ���\n",
                "$N�j�s�G�u��!��!�v�A��$n�ѤW���U�@�j��\n",
    }) );
           setup();
}

