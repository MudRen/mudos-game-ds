#include <mudlib.h>
#include <weapon.h>
#include <ansi.h>

inherit BOW;

string *name    = ({ HIW"�Ϣ١Т���"NOR});  
void create()
         {
          set_name("�Ϣ١Т���", ({"gun"}) );
          set_weight(1);
          if( clonep() )
                set_default_object(__FILE__);
          else {
               set("unit", "��");
               set("long","\n");
               seteuid(getuid());
               }
          init_bow(30);
          setup();
}

void init()
{
  add_action("fire", "shot");
}
int query_auto_load()
{
return 1;
}

int fire(string str)
{
  object target,targetenv,ob;
  ob=this_object();
  if(this_player() -> query("id") != "manto" && this_player() -> query("id") != "uchimaha")
  return notify_fail("�����ֹ藍�šA�L�k�ϥΦ��j�K!\n");
  if(!str || str == "") 
    {
      write(HIW"�A�ծg�F�@�j�Ӵ��ռu�D, �ݨӳo�j���B�b�̨Ϊ����p�C\n"NOR);
      tell_room(environment(this_player()), HIC+this_player()->query("name")
                +HIW"�|�_"+(string)ob -> query("name")+"�ծg�F�@�j, �ݨӤS���H�n�Q�t��F�C\n"NOR,
                ({this_object(), this_player()}));
      return 1;
    }
  target=present(str,environment(this_player()));
  if(!target) {
  write(HIC+"�j������M�ݲM���ؼЦA�g���T\n"+NOR);
  return 1;}
  targetenv=environment(target);
  write( HIW"�A�H�N����"HIC + (string)target -> query("name") + HIW"���X�@�u"
         + ", "NOR + RED"�ǽT�a�e��F�L�����U�T\n"NOR );
  tell_room(environment(this_player()),""+HIC
            +(string)this_player()->query("name")
            +HIW"�|�_"+(string)ob -> query("name")+"�A���"HIC + (string)target -> query("name")
            +HIW"���ܤߵo�X�@���l�u�T\n"NOR , ({this_player() , target}));

  tell_room(environment(target) , HIW"���M�@�n�j�T, �u���@���l�u�ǽT�a�e��F"HIC
            + (string)target -> query("name")
            + HIW"���B�Y�������T\n"NOR , ( { this_player() , target } ) );
     
  tell_object(target,
              HIW"���M�@�n�j�T, �@���l�u�w�g�e��F�A���B�Y�������T\n"NOR +
              "( �A"+RED"���˹L���M�w�g���p��������M�H�ɳ��i���_��C"NOR
              +" )\n");

  target -> set("env/immortal" , 0);
  this_object() -> destruct();
  target->set_temp("temp/death_type","[������`]"); 
  target -> die();  

  return 1;
}
int query_autoload() { return 1; }

