#include <ansi.h>
inherit NPC;
void create()
{
       set_name("Ĭ����",({"Dr.Sulivan","doctor","sulivan"}));
       set("long",@LONG
�@�ӪF�譱�ժ��k�l�A��۱`�����Ȧ�̦�ۡA�Y�v�b��������@��
�A¼�ۤG���L�ק��b�a�O�e���A���⮳�ۤ@�j�M���s�A�k�ⱷ�ۤ@���p��
�bŪ�A��L�ݨ��A�ɡA��A���F�@���A�ݨӬO�ӿˤ����n�H�C�ƹ�W�o��
�N�O���W���_�I��Dr.Sulivan�A�ǻ��L�O�q�F��Ӫ��A�b���j���Ȧ�A
��M�F�X�G��ӥ@�ɡA�]�]�������F�\�h�ǻ��P��G�A�A�i�H�ХL������
�ǬG�ơA�u�n���@�M���s�A�L�@�w�|�ַܼN���C
LONG);
       set("gender","�k��");
       set("age", 27);
       set("level", 77);
       set("nickname",HIW"Dr."NOR);
       set("attitude", "peaceful");

       set("chat_chance", 3);
       set("chat_msg", ({
            "Ĭ���害�_���s�B�P�B�P���ܤF�@�j�f�C\n",
            "Ĭ����N���½��U�@���A�S�z�z������Ū�F�_�ӡC\n",
            "Ĭ��������F�_�ӡA�S�F�@�j�f��C\n"
           }));
       set("talk_reply","�Qť�ڻ��G�ƶܡH�Чڤ@�M(have_a_drink)�ڴN�i�D�A�C:D~\n");
    
        setup();        
}
void init()
{
        ::init();
        add_action("do_story","have_a_drink");
}
int do_story()
{       
        string story="";
        int i,j,max;
        max = 1;
	while(read_file(__DIR__"obj/west_story.txt", max, 1))max++;//�p���`���(�p���|�h3)
        i = random(max-4)+1;//�q�Ҧ���Ƥ��H�N�D�@��
        //�M�w�q���@��}�Y
        while(strlen(read_file(__DIR__"obj/west_story.txt",i,1)) > 1)
        { 
                i++;
                if (i >= (max-3)) i=1;// ��i�I�쵲���ɡA���s�p��        
        }
        //�M�w�������a��
        j = i+1;//�q�аO�U�@���_
        while(strlen(read_file(__DIR__"obj/west_story.txt",j,1)) > 1)
        {
                j++;
        }

        //��J��ƨ�story
        story += HIY"Ĭ����ܤF�@�f���s�A�H�Իw���y�𻡹D�R\n"NOR;
        story += HIC+read_file(__DIR__"obj/west_story.txt",i+1,j-i)+NOR;
        //��X��player��
        this_player()->start_more(story);
        return 1;

}
