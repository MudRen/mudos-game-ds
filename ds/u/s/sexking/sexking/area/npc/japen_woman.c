#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�饻���k",({ "japen woman","woman","japen" }));
        set("long",
        "�L�O�@�Ӥ饻���H�A��W��ۤ@��"HIC"�p����"NOR"�A�{�l���G�]�٦��@���_�_�C\n"
        );
        set("age",32);
        set("level",10);
        set("gender", "�k��");
        set("exp",514);     
        set("combat_exp",500);         
        set("evil",-20);  
        set_skill("blade",25);          
        set_skill("parry",10);          
        set_skill("dodge",30);  
        set_skill("perception",5);
        set_skill("combat",25); 
        set("talk_reply","�_�_�L�@����������ı����O?�C");    
        set("chat_chance",5);
        set("inquiry",([
        "�{�l�̪��_�_" : "�ڧƱ�L�O�k���@�k�@�k���n!\n",
        "�p����" : "�_�_�L�@����������ı�����D���F...\n",
        ]));
        set("chat_msg", ({
        name()+"��ۤ�W���p����n�ڷn���C\n",
        name()+"�Τ�r�ۤ�W���p����C \n",
        name()+"��:�_�_�ġ�O���O���ֺ�ı��C\n",
        name()+"��ۧA��:�A����k�i�H���ڪ��_�_������?�C\n",
        "�Ať��饻���k��W�p�Ī����s�n�C\n",
       }) );
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
        "�饻���k�j�s�G�ϩR�ڡI���n���ڡI�ڨ{�l�٦��_�_�ڡC\n",
         (: command("sob") :),
         (: command("help!") :),
         }) );
        setup();
        carry_object(__DIR__"eq/woman_cloth")->wear();} 
        void die()
        {
        message_vision("$N�{�����e�����ڳڪ���:���٤��Q���r.....\n",this_object());
        ::die();}
int accept_object(object who,object ob)
{
     object me;
     me=this_player();
     if(this_player()->query("gender") )
     { 
     message_vision("$N���X�F�@"+ob->query("unit")+ob->query("name")+"���饻���k���_�_���C\n",who);
     command("say ��...���§A�{..�_�_.�j�������F�赹�A���F��..�ĨħO���C");
     call_out("toy",3,me);
     destruct(ob);
        return 1;
     }
    else
     {
    message_vision("$N���X�F�@"+ob->query("unit")+ob->query("name")+"���饻���k���_�_���C\n",who);
    command("say ��...���©p�{..�_�_.�j�j�j���F�赹�A���F��..�ĨħO���C");
    call_out("toy",3,me);
    destruct(ob);
    return 1;
        }
}
void toy(object me)
{
     if(!me) return;
     message_vision(HIC"�_�_��M�w�R�F�U��..�C\n"NOR,me);
     message_vision(HIY"�饻���k���������R�Ӧn�F!�_�_�����F...�C\n"NOR,me);
     call_out("toy1",3,this_player());  
     return;
}
void toy1(object me)
{
     if(!me) return;
     message_vision(HIR"�S�h�[�_�_�S���n�j���F�_��....>_<�C\n"NOR,me);
     message_vision(HIC"�饻���k���檺���R�_�_����ı����O??\n"NOR,me);
     command("sigh");
     return;
}

