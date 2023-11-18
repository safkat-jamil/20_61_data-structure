#include <gtk/gtk.h>

// Function to solve Tower of Hanoi
void tower_of_hanoi(int n, char source, char auxiliary, char target) {
    if (n > 0) {
        tower_of_hanoi(n - 1, source, target, auxiliary);
        g_print("Move disk %d from %c to %c\n", n, source, target);
        tower_of_hanoi(n - 1, auxiliary, source, target);
    }
}

// Callback function when the button is clicked
static void button_clicked(GtkWidget *widget, gpointer data) {
    int disks = GPOINTER_TO_INT(data);
    tower_of_hanoi(disks, 'A', 'B', 'C');
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Create the main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Tower of Hanoi Game");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 300, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a vertical box container
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Create a label
    GtkWidget *label = gtk_label_new("Tower of Hanoi Game");
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);

    // Create buttons for different disk sizes
    for (int i = 3; i <= 5; i++) {
        GtkWidget *button = gtk_button_new_with_label(g_strdup_printf("Start Game (%d Disks)", i));
        g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), GINT_TO_POINTER(i));
        gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);
    }

    // Show all widgets
    gtk_widget_show_all(window);

    // Run the GTK main loop
    gtk_main();

    return 0;
}
