#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�]�F��",({"bou da tin","bou","tin"}));
 set("long","�L�O�L��}���̳̪��ު��H, �������̪��ƾڻ��L�L�Ҥ���..�C\n");
 set("age",56);
 set("gender","�k��");
 set("level",30);
 set("title",HIG"�]��ť"NOR);
 set_skill("combat",100);
 set("chat_chance",20);
 set("chat_msg", ({"�]�F�ʻ��D: ���S��ԣ�Ƥ����D��...�ڥi�H��A��(talk)��!!..\n",
                   (:command("sigh"):),
 }));
	set("chat_chance_combat",200);

 set("chat_msg_combat",({                         
                         (:command,"hmm":),
 }));

	set("inquiry/�︹","�N�O���Q�̳̰Q�����︹��....�N�O���K���x��!\n"NOR);

	set("inquiry/����","�̪񺮰Ӫ����򳣫ܮt, �ҥH�]�����泽, �ݨӬO�@���ȿ����n���|�O!.\n"NOR);

	set("inquiry/�_��","ť���O�L������Ǯa���_? �쩳�Oԣ�]�S�H���L, ���L�@�w�b������v�̧a?.\n");

	set("inquiry/���H","�N�O�Q�L��! �L�����Q���ѫ�n���N����H�y�������a��F, ��������......\n"NOR);
 setup();
}

int talk_action(object me)        
{
 object book;
 if(!book=me->query_temp("notebook")) return 0;
 command("smile "+me->query("id") );
 if(random(2))
 {
        command("say �̪�L��Ưu�h�O!");
        command("say ť�����@�ǵL��̦b���L������y�_���z���D�N�O�C");
        command("say ���V�b���Q, �Q��~�a�F�Q�X�өx�L�����Fԣ�h�F?");
        command("say �̪񪺺�ì�������n, ť���y���ӡz�̳��n�h�ܦ�_���F....");
      command("say ť�����@�ӡy���H�z�h�����Q����, �p�������D���b���O!");
        command("sigh");
        command("say ������Q, �L�����ٯu�`�O! ���L�A�u�n�s�L���y�︹�z�L�@�w�|�� ");
 }
 
 return 1;
}