#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIY"�t"NOR HIC"�Ѷ��s"NOR, ({"god flying cloud-dragon", "god", "dragon" }));
        set("race", "robot");
        set("age", 1);
	set("title", HIY"�Ѧa���~"NOR);
	set("long", @long
�o�����~���O�ۤѦa�|�}�ХH�Ӥ@���u�@�ۤѦa�����~,�h�~���H�۩P�B�q
�M�U����ѭ̩��ԥ|��,�M�q�|��!���O�s�ڪ��̰���S,�۱q�J��F������
�D�P�B�q�N�@�����H�ۥL,�q�L�Ϯ�.����Ѧa�|�Хߤ���,�Q�P�B�q�U�ʬ�
�u�@�Ѧa�|���@�����~!!�q���Ѧa�|�W�n�j�_,�¾_����~!! 
long);
      set("level",25);
        set("mobhp",30);
        set_temp("apply/dodge",-999);
        set_temp("apply/armor",-10);
        setup();
}
void heart_beat()
{
  object obj,corpse;
  obj=this_object();
  if( obj->query("mobhp") < 0 )
  {
   corpse=new(__DIR__"ccopper");
    message_vision("\n��M$N�o�X�@�}�y�ء�ա�z���n�A$N�w�g���a�F�C\n",obj); 
     this_player()->remove_all_killer();
    destruct(this_object());
    //::die();
  } else obj->add_block(2);

  return; 
}

int receive_damage(string type,int damage,object who)
{
  int j,mobhp;
  object obj;
  obj=this_object();
  j=random(15)+1;
  if( !who ) return 0;
  who->add("exp", j);
  tell_object(who,"\n�A�o��F"+j+"�I���g��ȡC\n");
  mobhp=obj->query("mobhp");
  obj->set("mobhp",mobhp-1);  
  if(who->query("ap")>0)
  {
    who->receive_damage("ap",3);
  }
  else {
    who->receive_damage("hp",10);
  }
}
