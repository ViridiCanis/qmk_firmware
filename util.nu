export def get_index [info_json: path, row: int, col: int] {
    jaq $".layouts.LAYOUT_ansi_87.layout | to_entries[] | select\(.value.matrix | .[0] == ($row) and .[1] == ($col)).key" $info_json | into int | fmt
}
