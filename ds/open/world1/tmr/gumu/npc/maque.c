// maque.c

inherit NPC;

void create()
{
        set_name("�³�", ({ "maque bird", "bird"}));
        set("race", "���~");
        set("age", 3);
        set("long", "�@�u�p�³��A�b�۫Ǩ����W���U�C\n");
        set("attitude", "peaceful");

        set("chat_chance", 10);
        set("chat_msg", ({
                "�³��A�A���s�F�X�n�C\n",
                "�³����˵ۯͻH�C\n",
                "�³��@�U�����٤W�A���I���a�@�n�S���b�a�W�C\n",
        }) );

        setup();
}

