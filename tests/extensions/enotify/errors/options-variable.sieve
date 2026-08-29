require ["enotify", "variables"];

set "opt" "frop";

# The option is not a string literal, so it cannot be checked fully at compile
# time. Nothing about it is valid as an option name either, so the compile-time
# check must simply be skipped rather than reporting an error.
notify :options "${opt}" "mailto:stephan@example.org";

# Same, but for an empty option
notify :options "${nothing}" "mailto:stephan@example.org";
