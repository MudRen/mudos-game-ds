#include <ansi.h>
#include <armor.h>
inherit ANKLE;
void create()
{
  set_name(HIR"�t��"HIW"�ּ֨���"NOR,({"christmas ankle","ankle"}));
  set("long", @LONG  
�o�O�@��t�ϦѤH�R�Ϊ�����A²²��檺�u���A�f�t���_�۪��]�p�A
��y�X�t�ϸ`���w�֮�^�A�f�t����A�˳��D�`�n�ݡC
�o�O���ɪ̲ĤG�W�����~�G
��  �G�W ---- paper �y���n�� �G�Q�C�U�s�G�ʤT�Q�� �H��
LONG);
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume", 3);
    set("material","gold");
    set("no_drop",1);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_sell",1);
  }

  set("armor_prop/int",1 );
  set("armor_prop/str",1  );
  set("armor_prop/dex",1  );
  set("armor_prop/con",1  );
  set("armor_prop/armor", 5 );
  setup();
}

int query_autoload() { return 1; }

