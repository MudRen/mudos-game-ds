inherit NPC;

void create()
{
        set_name("�뭹�D�H",({"cook taoist","taoist"}) );
        set("long",@LONG
�@�Ӧb�H���D�[�̭t�d�뭹���D�H�A���M�w��j�椧�~�A���٬O�ѷ�
�q���B���o�ة����ˤl�A�ӬO�]���b�D�[�ר��i�ʡA�P�@�L�����߹Ҽv�T
�U�A�~�঳�o�ئѦӤ��o�����d����C
LONG
);
        set("age",70);
        set("race","�H��");
        set("level",15);
        set("attitude", "peaceful");
        set("gender", "�k��" );
        set("title","�H���D");
        set("chat_chance",10);
        set("chat_msg",({
                "�뭹�D�H���ۻy�D�G�u�T�Q���~�e���Ǩ��ٯu�O�O�H���H�ѰO��..�v�C\n",
                "�뭹�D�H�W���a���F���M�A��T�U�N���n�@��j�յ�F�C\n",
                "�뭹�D�H�q�@�Ǫ��j����̯�_�F���A���t�a�R�~�J�_�C\n",
        }) );

        set_skill("parry",40);
        set_skill("dodge",40);
        set_skill("unarmed",40);
        set("inquiry", ([
                "�Ǩ�": "��....���ɳh�D�����~�A�O���D�`�M���A�O�b�[���I�ǹJ�쪺�C",
                "�I��": "���ɳh�D�b�]�Τ��ۡA�Q���ӥh�I�ǭ���A�窾�j�@��i�A�Y�D��@�p����{���A�N�����H�ƤF�C",
                "��{��": "�{�b�Q�_�ӡA���M�O�o�O�ث����ߦӮ��ƪ����D�C",
        ]) );
        setup();
        carry_object(__DIR__"eq/shoe")->wear();
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");

}

