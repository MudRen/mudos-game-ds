#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIY"�t"NOR HIR"�ĴL��"NOR, ({ "god spirit-man", "man" }));
        set("race", "robot");
        set("age", 1);
	set("title", HIY"�����Ϫ�"NOR);
	set("long", @long
�o��O�Z�L���D�`���W�檺�t��,�~���ݰ_�ӥP���D�j�N�s��賣�O�t�大
��,���i�I��!!������ǳy�ګD�Z,�N�s�Z�\�]�D�`�H���,�N�s�T�j�����x
���H:�d��,�a�կP,����s���H�]�����Щ�L,��L�i���O�q�ؤ��w!�L�b�G 
�Q�~�e�h���ؤs�צ�,����Q�X�~�e�P�B�q�W�ؤs�b���t�U�J���F�o��t��
,�Ӧb�H�ۤѦa�|�}�Ф���,���D�H�j§�гo��t�̦^�Ӱ������Ϫ�~�s�Ѧa
�|���W(�Ѧa���k)�M���k��]�O�ѳo��e���Ҽ��g,�]��!�ϤѦa�|���u����
�ѤU�D�W���j��,�]���������H���Q�������t�P��!! 
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