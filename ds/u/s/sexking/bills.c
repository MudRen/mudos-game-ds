inherit ITEM;
void create()
{
        set_name("�ڤۤC��ǳ�", ({ "ds bills","ds","bills" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�i");
                set("long",
                        "�o�O�@�i�s�i�ǳ�A�W���g���w����[�ڤۤC������C\n"
                        "�ڭ̶��n�A������G\n"
                        "�Ш�:�C\n"
                        "home.pchome.com.tw/computer/dreamseven���[�a!\n");

                set("value", 0);
                  set("no_sac",1);
        }
}


