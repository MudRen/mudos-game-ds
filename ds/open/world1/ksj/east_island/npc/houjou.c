#include <ansi.h>
inherit NPC;

void create()
{
  set_name("�_��", ({ "houjou"}));
  set("long",@long
�@������ѹꪺ�A�H�A���b�и̤u�@�C
long);      
  set("gender", "�k��" );
  set("age",35);
  set("level",16);
  set("race","human");
  set("talk_reply","�и̸��ơA�p���I���A�n�䪺��a���ɷ|���D�X�S�A�̦n\n"
                  +"�O�h��½���O�C\n");
  set("chat_chance", 10);
  set("chat_msg", ({
      "�_���q�h�����X�@�i�}�����h�y�W�����C\n",
      "�_�����W�a�N�з��������d����@�ǡC\n",
      "�_���ݤF�A�@���A���`���D�G�z�n�C\n",
      "�_���ۻy�D�G���˪��~�ׯf�b�ɡA�ڻ�"HIW"�H����"NOR"�i�H�v�ʯf�A�i����M�O�H�C\n",
      (:command("sigh"):),
     }));
  set("inquiry/�H����","�N�O�H�����W���סAť�����H�b�e���ݨ��L�H���C\n");
  setup();
  add_money("coin",50+random(50));
}

int accept_object(object who,object ob)
{
  object obj,page,env;
  obj=this_object();
  env=environment(obj);

  if(ob->query("id") == "ningyo meat")
  {
    if(obj->is_busy() || obj->is_fighting())
    {
      command("whisper "+who->query("id")+" �ڨS�šA�O�ӷЧڡC\n");
      return 0;
    }
    message_vision("$N�����_���@�� "+ob->query("name")+"�C\n",who);
    command("really");
    message_vision("�_�����D�G�Ӧn�F�A���˦��ϤF�C\n\n",who);
    page=new_ob(__DIR__"eq/surcoat-design-page");
    page->move(env);
    tell_room(env,"�]�_�����ۤH���ץ^�^�a���F�A�^�����q�f�U�����@�i�ȡC�^\n");
    destruct(obj);
    return 1;
  }
  return 0;
}
