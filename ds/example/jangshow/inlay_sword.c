// Jangshow@DS ���� LPC �ɤ��@,��]�n�p�� =_=a
// �_���^�O��S��i�ɥR
// �@���}�� wp,�����H�W���|�g�d��
#include <ansi.h>
#include <weapon.h> 
#define WPNAME "�^�O���C"
inherit SWORD;

//string *stone= ({"�@�D�����I�g�Q�R�ѡI","

void create()
{
  set_name(HIY"�^�O���C"NOR , ({ "inlay sword","sword" }) ); 
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�W�����@�Ӥp�}�A�����D�O�F�ª�[inlay xxx]�C\n");
    set("material", "gold");
    set("value",30000);
  }
  set("weapon_prop/bar",1);
  set("weapon_prop/wit",1);
  set("weapon_prop/tec",1);
  set("weapon_prop/dodge",10);
//  set("weapon_prop/sword",10);    
  init_sword(60); 
  setup();
}
void init()
{
     add_action("do_inlay","inlay");
}
int do_inlay(string arg)
{ 
    object me=this_player(),obj;  
    if(this_object()->query_temp("inlaied")==1) 
       return notify_fail("�̭��w�g�^�F�@���_�ۡA�A�S�ݨ�ܡH\n");    

    /***************************************�^�O�}�l****************************************/ 

    if(!arg || arg !="red stone") return notify_fail("�A�n�^�O(inlay)����H\n"); 
              { 
               if(!objectp(obj=present("red stone",me)) ) return notify_fail("What?\n");
                   {
                    message_vision("\n$N�p���l�l���N"HIR"���_"NOR"�A�^�i�F"HIY""+WPNAME+"\n"NOR,me); 
                    this_object()->set("long","�o�O�@���^�F�@��"HIR"���_"NOR"���C�A�W�����p�}�w�g�Q�񺡤F�C\n"
                                           HIW"�S���O�G"HIR"���t"HIW"����\n"NOR);   
                    destruct(obj);
                    this_object()->set("no_drop",1);
                    this_object()->add_temp("inlaied",1); 
                    this_object()->add_temp("inlay/red",1);
                    } 
              }      
    if(!arg || arg !="blue stone") return notify_fail("�A�n�^�O(inlay)����H\n"); 
              { 
               if(!objectp(obj=present("blue stone",me)) ) return notify_fail("What?\n");
                   {
                    message_vision("\n$N�p���l�l���N"BLU"���_"NOR"�A�^�i�F"HIY""+WPNAME+"\n"NOR,me); 
                    this_object()->set("long","�o�O�@���^�F�@��"BLU"���_"NOR"���C�A�W�����p�}�w�g�Q�񺡤F�C\n"
                                           HIW"�S���O�G"BLU"���t"HIW"����\n"NOR);   
                    destruct(obj);
                    this_object()->set("no_drop",1);
                    this_object()->add_temp("inlaied",1); 
                    this_object()->add_temp("inlay/blue",1);
                    } 
              }  
    if(!arg || arg !="white stone") return notify_fail("�A�n�^�O(inlay)����H\n"); 
              { 
               if(!objectp(obj=present("white stone",me)) ) return notify_fail("What?\n");
                   {
                    message_vision("\n$N�p���l�l���N"HIW"���_"NOR"�A�^�i�F"HIY""+WPNAME+"\n"NOR,me); 
                    this_object()->set("long","�o�O�@���^�F�@��"HIW"���_"NOR"���C�A�W�����p�}�w�g�Q�񺡤F�C\n"
                                           HIW"�S���O�G"HIW"���t"HIW"����\n"NOR);   
                    destruct(obj);
                    this_object()->set("no_drop",1);
                    this_object()->add_temp("inlaied",1); 
                    this_object()->add_temp("inlay/white",1);
                    } 
              }     
    if(!arg || arg !="green stone") return notify_fail("�A�n�^�O(inlay)����H\n"); 
              { 
               if(!objectp(obj=present("green stone",me)) ) return notify_fail("What?\n");
                   {
                    message_vision("\n$N�p���l�l���N"HIG"���_"NOR"�A�^�i�F"HIY""+WPNAME+"\n"NOR,me); 
                    this_object()->set("long","�o�O�@���^�F�@��"HIG"���_"NOR"���C�A�W�����p�}�w�g�Q�񺡤F�C\n"
                                           HIW"�S���O�G"HIW"�r�t"HIW"����\n"NOR);   
                    destruct(obj);
                    this_object()->set("no_drop",1);
                    this_object()->add_temp("inlaied",1); 
                    this_object()->add_temp("inlay/green",1);
                    } 
              }      
              return 1;
}                                                    
                                                                                             
