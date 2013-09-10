(function ($) {

  Drupal.ajax.prototype.commands.isotope = function (ajax, response, status) {
    var oldView = $(response.selector);
    var oldItems = $('.node', oldView);

    var newView = $(response.data);
    var newItems = $('.node', newView);

    var oldIds = [];
    $.each(oldItems, function(index, oldItem) { oldIds.push($(oldItem).attr('id')); });

    var newIds = [];
    $.each(newItems, function(index, newItem) { newIds.push($(newItem).attr('id')); });

    var deleteIds = $(oldIds).not(newIds).get();

    $.each(deleteIds, function(index, deleteId) {
      $('.view-content', response.selector).isotope('remove', $('#' + deleteId, response.selector));
      $('.view-content', response.selector).isotope('reLayout');
    });

    $.each(newIds, function(index, newId) {
      if ($.inArray(newId, oldIds) === -1) {
        var appendItem = $('#' + newId, $(response.data));
        $('.view-content', response.selector).isotope('insert', $(appendItem));
      }
    });

  }

})(jQuery);

(function ($) {

  Drupal.behaviors.viewsIsotope = {
    attach: function (context, settings) {

      $.each(settings.views_isotope.views, function(index, view) {
        $('.' + view + ' .view-content').once().isotope();
      });

    }
  };

})(jQuery);
