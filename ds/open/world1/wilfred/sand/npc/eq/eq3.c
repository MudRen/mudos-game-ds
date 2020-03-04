#include <ansi.h>
#include <armor.h>
inherit F_UNIQUE;
inherit NECK;
void create()
{
  set_name(WHT"�����@��"NOR ,({ "divine-tree necklace","necklace" }) );
  set("long",HIW"�o�@�ŤW��۬۷���R���᯾�A���������ե��y��ۡA�O�H�������ءC"NOR);
  set_weight(900);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "wood");
    set("volume",4);
    set("unit", "��");
    set("value",12000);
    set("replica_ob",__DIR__"eq14");
  }

  set("armor_prop/armor",5);
  set("armor_prop/shield",25);
  set("armor_prop/dodge",7);
  set("armor_prop/int",4);
  set("armor_prop/con",-2);
   set("armor_prop/wit",1);
  set("armor_prop/bar",-1);

  set("beast_armor_prop/armor",5);
  set("beast_armor_prop/shield",25);
  set("beast_armor_prop/dodge",7);
  set("beast_armor_prop/int",4);
  set("beast_armor_prop/con",-2);
  set("beast_armor_prop/wit",2);
  set("beast_armor_prop/bar",-1);

        set("limit_level",30);
        set("limit_int",50);

  setup();

  set("power",10);
  set("max_power",10);
}

void init()
{
  add_action("do_look","look");
  if(query("is_defined"))
  {
    add_action("do_defence","defence");
    add_action("do_recharge","recharge");
  }
}

int do_look(string str)
{
  if(str == "�᯾")
  {
    if(query("is_defined"))
    {
      write("�᯾�W���N��O�G\n"HIC"�ۥ� ���O�榡: defence\n���O�^�_ ���O�榡: recharge\n"NOR);
      return 1;
    }
    write("�A�J�Ӫ��ݤF���@�ŤW���᯾�C\n");
    write("���R���᯾���G������@�ӭӤ�r�A������r�ëD����@��ҳq�Τ������C\n");
    write("�ݨӥ��ݧ�H�[�HŲ�w���[�H�P�_����r���N��C\n");
    return 1;
  }
  return 0;
}

int do_defence()
{
  object me = this_player(), ob = this_object();
  // �y��A�@
  return 1;
}

int do_recharge()
{
  object me = this_player(), ob = this_object();
  // �y��A�@
  return 1;
}
