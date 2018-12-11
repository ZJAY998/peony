#include "mime-utils.h"

char* get_mime_type_string_by_filename(char* filename){
	return g_file_info_get_content_type(
			g_file_query_info(
				g_file_new_for_path(filename),
				G_FILE_ATTRIBUTE_STANDARD_CONTENT_TYPE,
				0,
				g_cancellable_get_current (),
				NULL)
			);
}

gboolean is_text_type(char* filename){
	char* mime_type = get_mime_type_string_by_filename(filename);
	return strstr(mime_type,"text") ? TRUE : strstr(mime_type,"script") ? TRUE : FALSE;
}

gboolean is_pdf_type(char* filename){
	char* mime_type = get_mime_type_string_by_filename(filename);
	return strstr(mime_type,"pdf") ?  TRUE : FALSE;
}
